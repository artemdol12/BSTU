#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <Windows.h>
using namespace std;

union Detail {
    char product[100];
    char address[100];
};

struct Item {
    char client[100];
    char type; // 'T' - товар, 'R' - недвижимость
    Detail detail;
    float value;
    float loan;
    char date[11];
    int storage;
};

vector<Item> items;

void inputItem(Item& i) {
    cout << "Клиент: "; cin.ignore(); cin.getline(i.client, 100);
    cout << "Тип (T/R): "; cin >> i.type; cin.ignore();
    if (i.type == 'T') {
        cout << "Товар: "; cin.getline(i.detail.product, 100);
    }
    else {
        cout << "Адрес: "; cin.getline(i.detail.address, 100);
    }
    cout << "Оценка: "; cin >> i.value;
    cout << "Залог: "; cin >> i.loan;
    cout << "Дата (ДД.ММ.ГГГГ): "; cin >> i.date;
    cout << "Срок (дни): "; cin >> i.storage;
}

void printItem(const Item& i) {
    cout << "\nКлиент: " << i.client
        << "\nТип: " << (i.type == 'T' ? "Товар" : "Недвижимость")
        << "\nНазвание: " << (i.type == 'T' ? i.detail.product : i.detail.address)
        << "\nОценка: " << i.value
        << "\nЗалог: " << i.loan
        << "\nДата: " << i.date
        << "\nСрок: " << i.storage << " дней\n";
}

void saveToFile(const char* filename) {
    ofstream f(filename, ios::binary);
    for (const auto& i : items) f.write((char*)&i, sizeof(Item));
}

void loadFromFile(const char* filename) {
    ifstream f(filename, ios::binary);
    Item i;
    items.clear();
    while (f.read((char*)&i, sizeof(Item))) items.push_back(i);
}

void searchByName(const char* name) {
    for (const auto& i : items)
        if (i.type == 'T' && strcmp(i.detail.product, name) == 0)
            printItem(i);
}

void menu() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int choice;
    char filename[100];
    char name[100];
    Item item;

    do {
        cout << "\n1. Добавить\n2. Вывести\n3. Сохранить\n4. Загрузить\n5. Поиск\n6. Выход\nВыбор: ";
        cin >> choice;
        switch (choice) {
        case 1: inputItem(item); items.push_back(item); break;
        case 2: for (const auto& i : items) printItem(i); break;
        case 3: cout << "Файл: "; cin >> filename; saveToFile(filename); break;
        case 4: cout << "Файл: "; cin >> filename; loadFromFile(filename); break;
        case 5: cout << "Название: "; cin >> name; searchByName(name); break;
        }
    } while (choice != 6);
}

int main() {
    menu();
}