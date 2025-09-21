#include <iostream>
#include <fstream>
#include <cstring>
#include <Windows.h>
#include <limits> // Для numeric_limits
#define STR_LEN 50
#define LIST_SIZE 30

using namespace std;

// Перечисление для процента торговой надбавки
enum Markup {
    MARKUP_5 = 5,
    MARKUP_10 = 10,
    MARKUP_15 = 15,
    MARKUP_20 = 20,
    MARKUP_35 = 35,
    MARKUP_30 = 30
};

// Объединение для дополнительной информации о товаре
union ProductDetails {
    char supplier[STR_LEN];  // Поставщик
    char productionDate[STR_LEN]; // Дата производства
};

// Структура для хранения информации о товаре
struct Product {
    char name[STR_LEN];
    double price;
    int quantity;
    Markup markup;
    ProductDetails details;
};

Product warehouse[LIST_SIZE];
int current_size = 0;

void enter_new();
void del();
void out();
void search();
void saveToFile();
void loadFromFile();
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
        cout << "5 - для сохранения в файл" << endl;
        cout << "6 - для загрузки из файла" << endl;
        cout << "7 - для выхода" << endl;
        cin >> choice;
        clear_buffer();
        switch (choice) {
        case 1: enter_new(); break;
        case 2: out(); break;
        case 3: del(); break;
        case 4: search(); break;
        case 5: saveToFile(); break;
        case 6: loadFromFile(); break;
        case 7: cout << "Выход из программы." << endl; break;
        default: cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 7);
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
    clear_buffer();
    cout << "Количество: ";
    cin >> warehouse[current_size].quantity;
    clear_buffer();

    // Ввод процента надбавки
    int markup;
    cout << "Надбавка (5, 10, 15, 20, 35, 30): ";
    cin >> markup;
    warehouse[current_size].markup = static_cast<Markup>(markup);
    clear_buffer();

    // Ввод дополнительной информации
    cout << "Дополнительная информация (1 - Поставщик, 2 - Дата производства): ";
    int detailChoice;
    cin >> detailChoice;
    clear_buffer();
    switch (detailChoice) {
    case 1:
        cout << "Поставщик: ";
        cin.getline(warehouse[current_size].details.supplier, STR_LEN);
        break;
    case 2:
        cout << "Дата производства: ";
        cin.getline(warehouse[current_size].details.productionDate, STR_LEN);
        break;
    default:
        cout << "Неверный выбор. Дополнительная информация не добавлена." << endl;
        break;
    }

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
            cout << "Дополнительная информация: ";
            if (strlen(warehouse[n - 1].details.supplier) > 0) {
                cout << "Поставщик: " << warehouse[n - 1].details.supplier << endl;
            }
            else if (strlen(warehouse[n - 1].details.productionDate) > 0) {
                cout << "Дата производства: " << warehouse[n - 1].details.productionDate << endl;
            }
            else {
                cout << "Нет данных" << endl;
            }
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
                cout << "Дополнительная информация: ";
                if (strlen(warehouse[i].details.supplier) > 0) {
                    cout << "Поставщик: " << warehouse[i].details.supplier << endl;
                }
                else if (strlen(warehouse[i].details.productionDate) > 0) {
                    cout << "Дата производства: " << warehouse[i].details.productionDate << endl;
                }
                else {
                    cout << "Нет данных" << endl;
                }
                cout << "-----------------------------" << endl;
            }
        }
    }
    else {
        cout << "Неверный выбор." << endl;
    }
}

void search() {
    char query[STR_LEN];
    cout << "Введите наименование товара для поиска: ";
    cin.getline(query, STR_LEN);
    bool found = false;
    for (int i = 0; i < current_size; i++) {
        if (strstr(warehouse[i].name, query) != nullptr) {
            cout << "Найдено:" << endl;
            cout << "Наименование: " << warehouse[i].name << endl;
            cout << "Цена: " << warehouse[i].price << endl;
            cout << "Количество: " << warehouse[i].quantity << endl;
            cout << "Надбавка: " << getMarkupName(warehouse[i].markup) << "%" << endl;
            cout << "Дополнительная информация: ";
            if (strlen(warehouse[i].details.supplier) > 0) {
                cout << "Поставщик: " << warehouse[i].details.supplier << endl;
            }
            else if (strlen(warehouse[i].details.productionDate) > 0) {
                cout << "Дата производства: " << warehouse[i].details.productionDate << endl;
            }
            else {
                cout << "Нет данных" << endl;
            }
            found = true;
        }
    }
    if (!found) {
        cout << "Ничего не найдено." << endl;
    }
}

void saveToFile() {
    ofstream file("warehouse.dat", ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    file.write((char*)&current_size, sizeof(current_size)); // Сохраняем количество записей
    file.write((char*)warehouse, current_size * sizeof(Product)); // Сохраняем только актуальные данные
    file.close();
    cout << "Данные сохранены в файл." << endl;
}

void loadFromFile() {
    ifstream file("warehouse.dat", ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    file.read((char*)&current_size, sizeof(current_size)); // Читаем количество записей
    file.read((char*)warehouse, current_size * sizeof(Product)); // Читаем только актуальные данные
    file.close();
    cout << "Данные загружены из файла." << endl;
}

const char* getMarkupName(Markup markup) {
    switch (markup) {
    case MARKUP_5: return "5";
    case MARKUP_10: return "10";
    case MARKUP_15: return "15";
    case MARKUP_20: return "20";
    case MARKUP_35: return "35";
    case MARKUP_30: return "30";
    default: return "Неизвестно";
    }
}

void clear_buffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}