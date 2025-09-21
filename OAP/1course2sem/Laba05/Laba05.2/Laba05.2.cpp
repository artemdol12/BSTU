#include <iostream>
#include <windows.h>
#include <cstring>
#define STR_LEN 50
#define LIST_SIZE 30

using namespace std;

enum Markup {
    MARKUP_5 = 5,
    MARKUP_7 = 7,
    MARKUP_11 = 11,
    MARKUP_20 = 20,
    MARKUP_25 = 25,
    MARKUP_30 = 30
};

struct Product {
    char name[STR_LEN];
    double price;
    int quantity;
    Markup markup;
};

Product warehouse[LIST_SIZE];
int current_size = 0;

void enter_new();
void del();
void out();
void search();
void clear_buffer();
const char* getMarkupName(Markup markup);

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
    cout << "Наименование товара: ";
    cin.getline(warehouse[current_size].name, STR_LEN);
    cout << "Цена: ";
    cin >> warehouse[current_size].price;
    cout << "Количество: ";
    cin >> warehouse[current_size].quantity;

    int markup;
    cout << "Надбавка (5, 7, 11, 20, 25, 30): ";
    cin >> markup;
    warehouse[current_size].markup = static_cast<Markup>(markup);
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
            warehouse[i] = warehouse[i + 1];
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
            cout << "Наименование: " << warehouse[n - 1].name << endl;
            cout << "Цена: " << warehouse[n - 1].price << endl;
            cout << "Количество: " << warehouse[n - 1].quantity << endl;
            cout << "Надбавка: " << getMarkupName(warehouse[n - 1].markup) << "%" << endl;
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
                cout << "Наименование: " << warehouse[i].name << endl;
                cout << "Цена: " << warehouse[i].price << endl;
                cout << "Количество: " << warehouse[i].quantity << endl;
                cout << "Надбавка: " << getMarkupName(warehouse[i].markup) << "%" << endl;
                cout << "-----------------------------" << endl;
            }
        }
    }
    else {
        cout << "Неверный выбор." << endl;
    }
}

void search() {
    double price;
    cout << "Введите цену для поиска: ";
    cin >> price;
    clear_buffer();
    bool found = false;
    for (int i = 0; i < current_size; i++) {
        if (warehouse[i].price == price) {
            cout << "Найдено:" << endl;
            cout << "Наименование: " << warehouse[i].name << endl;
            cout << "Цена: " << warehouse[i].price << endl;
            cout << "Количество: " << warehouse[i].quantity << endl;
            cout << "Надбавка: " << getMarkupName(warehouse[i].markup) << "%" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Ничего не найдено." << endl;
    }
}

const char* getMarkupName(Markup markup) {
    switch (markup) {
    case MARKUP_5: return "5";
    case MARKUP_7: return "7";
    case MARKUP_11: return "11";
    case MARKUP_20: return "20";
    case MARKUP_25: return "25";
    case MARKUP_30: return "30";
    default: return "Неизвестно";
    }
}

void clear_buffer() {
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
}