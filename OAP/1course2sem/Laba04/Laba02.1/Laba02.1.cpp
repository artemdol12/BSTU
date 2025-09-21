#include <iostream>
#include <windows.h>
#include <cstring>
#define STR_LEN 50
#define LIST_SIZE 30

using namespace std;

struct Sanatorium {
    char name[STR_LEN];
    char location[STR_LEN];
    char profile[STR_LEN];
    int vouchers;
};

Sanatorium list_of_sanatoriums[LIST_SIZE];
int current_size = 0;

void enter_new();
void del();
void out();
void search();
void clear_buffer();

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int choice;
    do {
        cout << "Введите:" << endl;
        cout << "1 - для ввода новой записи" << endl;
        cout << "2 - для вывода записи(ей)" << endl;
        cout << "3 - для удаления записи" << endl;
        cout << "4 - для поиска записи" << endl;
        cout << "5 - для выхода" << endl;
        cin >> choice;
        clear_buffer();
        switch (choice) {
        case 1: enter_new(); break;
        case 2: out(); break;
        case 3: del(); break;
        case 4: search(); break;
        case 5: cout << "Выход из программы." << endl; break;
        default: cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 5);
    return 0;
}

void enter_new() {
    if (current_size >= LIST_SIZE) {
        cout << "Введено максимальное количество записей." << endl;
        return;
    }
    cout << "Ввод информации" << endl;
    cout << "Строка номер " << current_size + 1 << endl;
    cout << "Название санатория: ";
    cin.getline(list_of_sanatoriums[current_size].name, STR_LEN);
    cout << "Место расположения: ";
    cin.getline(list_of_sanatoriums[current_size].location, STR_LEN);
    cout << "Лечебный профиль: ";
    cin.getline(list_of_sanatoriums[current_size].profile, STR_LEN);
    cout << "Количество путевок: ";
    cin >> list_of_sanatoriums[current_size].vouchers;
    clear_buffer();
    current_size++;
    cout << "Запись добавлена." << endl;
}

void del() {
    int d;
    cout << "\nНомер строки, которую надо удалить (для удаления всех строк введите 99): ";
    cin >> d;
    clear_buffer();
    if (d == 99) {
        current_size = 0;
        cout << "Все записи удалены." << endl;
    }
    else if (d > 0 && d <= current_size) {
        for (int i = d - 1; i < current_size - 1; i++) {
            list_of_sanatoriums[i] = list_of_sanatoriums[i + 1];
        }
        current_size--;
        cout << "Запись удалена." << endl;
    }
    else {
        cout << "Неверный номер строки." << endl;
    }
}

void out() {
    int sw;
    cout << "1 - вывод одной строки" << endl;
    cout << "2 - вывод всех строк" << endl;
    cin >> sw;
    clear_buffer();
    if (sw == 1) {
        int n;
        cout << "Номер выводимой строки: ";
        cin >> n;
        clear_buffer();
        if (n > 0 && n <= current_size) {
            cout << "Название: " << list_of_sanatoriums[n - 1].name << endl;
            cout << "Место: " << list_of_sanatoriums[n - 1].location << endl;
            cout << "Профиль: " << list_of_sanatoriums[n - 1].profile << endl;
            cout << "Путевок: " << list_of_sanatoriums[n - 1].vouchers << endl;
        }
        else {
            cout << "Неверный номер строки." << endl;
        }
    }
    else if (sw == 2) {
        if (current_size == 0) {
            cout << "Список пуст." << endl;
        }
        else {
            for (int i = 0; i < current_size; i++) {
                cout << "Запись №" << i + 1 << ":" << endl;
                cout << "Название: " << list_of_sanatoriums[i].name << endl;
                cout << "Место: " << list_of_sanatoriums[i].location << endl;
                cout << "Профиль: " << list_of_sanatoriums[i].profile << endl;
                cout << "Путевок: " << list_of_sanatoriums[i].vouchers << endl;
                cout << "-----------------------------" << endl;
            }
        }
    }
    else {
        cout << "Неверный выбор." << endl;
    }
}

void search() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char query[STR_LEN];
    cout << "Введите название санатория для поиска: ";
    cin.getline(query, STR_LEN);
    bool found = false;
    for (int i = 0; i < current_size; i++) {
        if (strstr(list_of_sanatoriums[i].name, query) != nullptr) {
            cout << "Найдено:" << endl;
            cout << "Название: " << list_of_sanatoriums[i].name << endl;
            cout << "Место: " << list_of_sanatoriums[i].location << endl;
            cout << "Профиль: " << list_of_sanatoriums[i].profile << endl;
            cout << "Путевок: " << list_of_sanatoriums[i].vouchers << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Ничего не найдено." << endl;
    }
}

void clear_buffer() {
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
}