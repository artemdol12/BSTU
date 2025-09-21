#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cstring>
using namespace std;

const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address {
    char name[NAME_SIZE];
    char city[CITY_SIZE];
    Address* next;
    Address* prev;
};

// Добавленные прототипы функций
void insertEnd(void* data, Address** phead, Address** plast);
Address* findMax(int fieldChoice);

//-----------------------------------------------------------
int menu(void) {
    system("cls");
    int c;
    cout << "\n";
    cout << "1. Ввод имени\n";
    cout << "2. Удаление имени\n";
    cout << "3. Вывод на экран\n";
    cout << "4. Поиск\n";
    cout << "5. Добавить в конец (insertEnd)\n";  // Измененный пункт
    cout << "6. Найти максимум (findMax)\n";      // Измененный пункт
    cout << "7. Запись в файл\n";
    cout << "8. Вывести из файла\n";
    cout << "9. Удаление каждого M-ого элемента\n";
    cout << "10. Выход\n\n";                      // Обновленные номера пунктов

    do {
        cout << "Ваш выбор: ";
        cin >> c;
        cin.ignore(cin.rdbuf()->in_avail());
    } while (c < 1 || c > 10);
    return c;
}

//-----------------------------------------------------------
void insert(Address* e, Address** phead, Address** plast) {
    if (*plast == NULL) {
        e->next = NULL;
        e->prev = NULL;
        *plast = e;
        *phead = e;
    }
    else {
        e->prev = *plast;
        (*plast)->next = e;
        *plast = e;
        e->next = NULL;
    }
}

// Новая функция добавления в конец
//-----------------------------------------------------------
// Новая функция добавления в конец через void*
void insertEnd(void* data, Address** phead, Address** plast) {
    Address* newAddr = static_cast<Address*>(data);
    newAddr->next = nullptr;
    newAddr->prev = *plast;

    if (*plast) {
        (*plast)->next = newAddr;
    }
    else {
        *phead = newAddr;
    }
    *plast = newAddr;
}

//-----------------------------------------------------------
// Новая функция поиска максимума
Address* findMax(int fieldChoice, Address** phead) {
    if (!*phead) {
        cout << "Список пуст!\n";
        return nullptr;
    }

    Address* maxNode = *phead;
    Address* current = *phead;

    while (current) {
        int compareResult;
        switch (fieldChoice) {
        case 1: // По имени
            compareResult = strcmp(current->name, maxNode->name);
            break;
        case 2: // По городу
            compareResult = strcmp(current->city, maxNode->city);
            break;
        default:
            cout << "Неверный выбор поля!\n";
            return nullptr;
        }

        if (compareResult > 0) {
            maxNode = current;
        }
        current = current->next;
    }
    return maxNode;
}

//-----------------------------------------------------------
Address* setElement() {
    Address* temp = new Address();
    cout << "Введите имя: ";
    cin.getline(temp->name, NAME_SIZE);
    cout << "Введите город: ";
    cin.getline(temp->city, CITY_SIZE);
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

//-----------------------------------------------------------
void outputList(Address** phead) {
    Address* t = *phead;
    while (t) {
        cout << t->name << " " << t->city << endl;
        t = t->next;
    }
    system("pause");
}

//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address** phead) {
    Address* t = *phead;
    while (t) {
        if (strcmp(t->name, name) == 0) {
            cout << "Найден: " << t->name << " " << t->city << endl;
            system("pause");
            return;
        }
        t = t->next;
    }
    cout << "Не найдено!\n";
    system("pause");
}
void writeToFile(Address** phead) {
    ofstream fout("data.dat", ios::binary);
    Address* t = *phead;
    while (t) {
        fout.write((char*)t, sizeof(Address));
        t = t->next;
    }
    fout.close();
    cout << "Сохранено!\n";
    system("pause");
}

//-----------------------------------------------------------
void readFromFile(Address** phead, Address** plast) {
    ifstream fin("data.dat", ios::binary);
    if (!fin) {
        cout << "Файл не найден!\n";
        system("pause");
        return;
    }

    while (*phead) {
        Address* temp = (*phead)->next;
        delete* phead;
        *phead = temp;
    }
    *phead = *plast = NULL;

    Address temp;
    while (fin.read((char*)&temp, sizeof(Address))) {
        Address* newNode = new Address();
        *newNode = temp;
        insert(newNode, phead, plast);
    }
    fin.close();
    cout << "Загружено!\n";
    system("pause");
}

//-----------------------------------------------------------
void deleteEveryM(int m, Address** phead, Address** plast) {
    if (m < 1) return;

    int counter = 1;
    Address* current = *phead;

    while (current) {
        Address* nextNode = current->next;
        if (counter % m == 0) {
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            if (current == *phead) *phead = current->next;
            if (current == *plast) *plast = current->prev;
            delete current;
        }
        counter++;
        current = nextNode;
    }
    cout << "Удаление завершено!\n";
    system("pause");
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address** phead, Address** plast) {
    Address* t = *phead;
    while (t) {
        if (strcmp(t->name, name) == 0) {
            if (t->prev) t->prev->next = t->next;
            if (t->next) t->next->prev = t->prev;
            if (t == *phead) *phead = t->next;
            if (t == *plast) *plast = t->prev;
            delete t;
            cout << "Удалено!\n";
            system("pause");
            return;
        }
        t = t->next;
    }
    cout << "Не найдено!\n";
    system("pause");
}
//-----------------------------------------------------------
Address* findMax(int fieldChoice) {
    static Address* maxNode = nullptr;
    // Реализация поиска максимума
    // fieldChoice: 1 - по имени, 2 - по городу
    return maxNode;
}

//-----------------------------------------------------------
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(0, "Rus");

    Address* head = NULL;
    Address* last = NULL;

    while (true) {
        switch (menu()) {
        case 1: insert(setElement(), &head, &last); break;
        case 2: {
            char name[NAME_SIZE];
            cout << "Введите имя для удаления: ";
            cin.getline(name, NAME_SIZE);
            delet(name, &head, &last);
            break;
        }
        case 3: outputList(&head); break;
        case 4: {
            char name[NAME_SIZE];
            cout << "Введите имя для поиска: ";
            cin.getline(name, NAME_SIZE);
            find(name, &head);
            break;
        }
        case 5: {  // Новый пункт для insertEnd
            Address* newElement = setElement();
            insertEnd(static_cast<void*>(newElement), &head, &last);
            break;
        }
        case 6: {  // Новый пункт для findMax
            int choice;
            cout << "Выберите поле для сравнения (1 - Имя, 2 - Город): ";
            cin >> choice;
            Address* max = findMax(choice);
            if (max) {
                cout << "Максимальный элемент: "
                    << max->name << " " << max->city << endl;
            }
            system("pause");
            break;
        }
        case 7: writeToFile(&head); break;
        case 8: readFromFile(&head, &last); break;
        case 9: {
            int m;
            cout << "Введите M: ";
            cin >> m;
            cin.ignore();
            deleteEveryM(m, &head, &last);
            break;
        }

              // Остальные case обновляются соответственно...
        case 10: exit(0);
        }
    }
    return 0;
}