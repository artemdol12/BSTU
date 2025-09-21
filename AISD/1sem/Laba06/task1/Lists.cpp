#include <iostream>
#include <string>
#include <chrono>
#include <Windows.h> 
using namespace std;
using namespace chrono;

struct PhoneRecord {
    int phoneNumber;
    string ownerName;
};

struct ChainNode {
    PhoneRecord data;
    ChainNode* next;
};

class HashTable {
private:
    ChainNode** table;
    int size;

    int hashFunction(int phoneNumber) {
        return phoneNumber % size;
    }

public:
    void initialize(int tableSize) {
        size = tableSize;
        table = new ChainNode * [size];
        for (int i = 0; i < size; i++) {
            table[i] = nullptr;
        }
    }
    
    bool insert(int phoneNumber, const string& ownerName) {
        int index = hashFunction(phoneNumber);

        ChainNode* newNode = new ChainNode;
        newNode->data.phoneNumber = phoneNumber;
        newNode->data.ownerName = ownerName;
        newNode->next = table[index];
        table[index] = newNode;

        return true;
    }

   
    PhoneRecord* search(int phoneNumber) {
        int index = hashFunction(phoneNumber);
        ChainNode* current = table[index];

        while (current != nullptr) {
            if (current->data.phoneNumber == phoneNumber) {
                return &(current->data);
            }
            current = current->next;
        }

        return nullptr;
    }

    
    bool remove(int phoneNumber) {
        int index = hashFunction(phoneNumber);
        ChainNode* current = table[index];
        ChainNode* prev = nullptr;

        while (current != nullptr) {
            if (current->data.phoneNumber == phoneNumber) {
                if (prev == nullptr) {
                    table[index] = current->next;
                }
                else {
                    prev->next = current->next;
                }
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }

        return false;
    }

    
    void print() {
        for (int i = 0; i < size; i++) {
            cout << "[" << i << "]: ";
            ChainNode* current = table[i];
            if (current == nullptr) {
                cout << "пусто";
            }
            while (current != nullptr) {
                cout << current->data.phoneNumber << " - "
                    << current->data.ownerName;
                if (current->next != nullptr) {
                    cout << " -> ";
                }
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    HashTable ht;
    int choice;
    int tableSize;
    long long int phoneNumber;
    string ownerName;
    cout << "Введите размер таблицы: ";
    cin >> tableSize;
    ht.initialize(tableSize);
    cin.ignore();
    do {
        cout << "1. Добавить запись\n";
        cout << "2. Удалить запись\n";
        cout << "3. Найти запись\n";
        cout << "4. Вывести всю таблицу\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Введите номер телефона: ";
            cin >> phoneNumber;
            cin.ignore();
            cout << "Введите ФИО: ";
            getline(cin, ownerName);
            ht.insert(phoneNumber, ownerName);
            break;
        }
        case 2: {
            cout << "Введите номер телефона для удаления: ";
            cin >> phoneNumber;
            ht.remove(phoneNumber);
            break;
        }
        case 3: {
            cout << "Введите номер телефона для поиска: ";
            cin >> phoneNumber;
            auto start = high_resolution_clock::now();
            PhoneRecord* found = ht.search(phoneNumber);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            if (found != nullptr) {
                cout << "Найдена запись: " << found->phoneNumber << " - " << found->ownerName << endl;
                cout << "Время поска намера телефона в таблице составило: " << duration.count() << "мкс" << endl;

            }
            else {
                cout << "Запись не найдена!\n";
            }
            break;
        }
        case 4: {
            ht.print();
            break;
        }
        case 0: {
            cout << "Выход из программы...\n";
            break;
        }
        default: {
            cout << "Неверный выбор! Попробуйте снова.\n";
            break;
        }
        }
    } while (choice != 0);

    return 0;
}