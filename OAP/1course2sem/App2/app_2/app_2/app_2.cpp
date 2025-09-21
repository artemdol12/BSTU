#include "List.h"
#include <iostream>
using namespace std;

struct Person {
    char name[20];
    int age;
    Person* next;
};

void print(void* b) {
    Person* a = (Person*)b;
    cout << a->name << "  " << a->age << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Object L1 = Create();
    int choice;
    Person* newPerson;
    char name[20];
    int age;

    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить элемент в начало\n";
        cout << "2. Добавить элемент в конец\n";
        cout << "3. Удалить элемент\n";
        cout << "4. Найти элемент\n";
        cout << "5. Вывести список\n";
        cout << "6. Подсчитать количество элементов\n";
        cout << "7. Удалить весь список\n";
        cout << "8. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: { // Добавить в начало
            newPerson = new Person;
            cout << "Введите имя: ";
            cin.getline(newPerson->name, 20);
            cout << "Введите возраст: ";
            cin >> newPerson->age;
            L1.Insert(newPerson);
            break;
        }

        case 2: { // Добавить в конец
            newPerson = new Person;
            cout << "Введите имя: ";
            cin.getline(newPerson->name, 20);
            cout << "Введите возраст: ";
            cin >> newPerson->age;
            L1.InsertEnd(newPerson);
            break;
        }
        case 3: { // Удалить элемент
            cout << "Введите имя для удаления: ";
            cin.getline(name, 20);
            // Для простоты ищем по имени
            Element* e = L1.GetFirst();
            bool found = false;
            while (e != NULL) {
                Person* p = (Person*)e->Data;
                if (strcmp(p->name, name) == 0) {
                    L1.Delete(e);
                    found = true;
                    cout << "Элемент удален\n";
                    break;
                }
                e = e->GetNext();
            }
            if (!found) cout << "Элемент не найден\n";
            break;
        }
        case 4: { // Найти элемент
            cout << "Введите имя для поиска: ";
            cin.getline(name, 20);
            Element* e = L1.GetFirst();
            bool found = false;
            while (e != NULL) {
                Person* p = (Person*)e->Data;
                if (strcmp(p->name, name) == 0) {
                    cout << "Найден: ";
                    print(p);
                    found = true;
                    break;
                }
                e = e->GetNext();
            }
            if (!found) cout << "Элемент не найден\n";
            break;
        }
        case 5: {// Вывести список
            cout << "Список:\n";
            L1.PrintList(print);
            break;
        }
        case 6: {// Подсчитать элементы
            cout << "Количество элементов: " << L1.CountList() << endl;
            break;
        }
        case 7: { // Удалить список
            L1.DeleteList();
            cout << "Список очищен\n";
            break;
        }
        case 8: {// Выход
            cout << "Выход...\n";
            break;
            }
        default:
            cout << "Неверный выбор!\n";
        }
    } while (choice != 8);

    // Очистка памяти перед выходом
    L1.DeleteList();
    return 0;
}