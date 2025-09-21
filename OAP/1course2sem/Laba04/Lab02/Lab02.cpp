#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <locale>
#include <windows.h> 

using namespace std;

struct Client {
    string fullName;
    string accountType;
    int accountNumber;
    double balance;
    string lastUpdateDate;
};

Client inputClient() {
    Client client;
    cout << "Введите ФИО клиента: ";
    getline(cin, client.fullName);
    cout << "Введите тип счета: ";
    getline(cin, client.accountType);
    cout << "Введите номер счета: ";
    cin >> client.accountNumber;
    cout << "Введите сумму на счете: ";
    cin >> client.balance;
    cin.ignore();
    cout << "Введите дату последнего изменения (дд.мм.гггг): ";
    getline(cin, client.lastUpdateDate);
    return client;
}

void printClient(const Client& client) {
    cout << "ФИО: " << client.fullName << endl;
    cout << "Тип счета(льготный, срочный и т.д.): " << client.accountType << endl;
    cout << "Номер счета: " << client.accountNumber << endl;
    cout << "Сумма на счете: " << fixed << setprecision(2) << client.balance << endl;
    cout << "Дата последнего изменения: " << client.lastUpdateDate << endl;
}

void deleteClient(vector<Client>& clients, int accountNumber) {
    for (auto it = clients.begin(); it != clients.end(); ++it) {
        if (it->accountNumber == accountNumber) {
            clients.erase(it);
            cout << "Клиент с номером счета " << accountNumber << " удален." << endl;
            return;
        }
    }
    cout << "Клиент с номером счета " << accountNumber << " не найден." << endl;
}

void findClient(const vector<Client>& clients, int accountNumber) {
    for (const auto& client : clients) {
        if (client.accountNumber == accountNumber) {
            printClient(client);
            return;
        }
    }
    cout << "Клиент с номером счета " << accountNumber << " не найден." << endl;
}

void writeToFile(const vector<Client>& clients, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Ошибка открытия файла для записи." << endl;
        return;
    }
    for (const auto& client : clients) {
        outFile << client.fullName << endl;
        outFile << client.accountType << endl;
        outFile << client.accountNumber << endl;
        outFile << client.balance << endl;
        outFile << client.lastUpdateDate << endl;
    }
    outFile.close();
    cout << "Данные записаны в файл " << filename << endl;
}

void readFromFile(vector<Client>& clients, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Ошибка открытия файла для чтения." << endl;
        return;
    }
    clients.clear();
    Client client;
    while (getline(inFile, client.fullName)) {
        getline(inFile, client.accountType);
        inFile >> client.accountNumber;
        inFile >> client.balance;
        inFile.ignore();
        getline(inFile, client.lastUpdateDate);
        clients.push_back(client);
    }
    inFile.close();
    cout << "Данные прочитаны из файла " << filename << endl;
}

void displayMenu() {
    cout << "Меню:" << endl;
    cout << "1. Добавить клиента" << endl;
    cout << "2. Вывести всех клиентов" << endl;
    cout << "3. Удалить клиента по номеру счета" << endl;
    cout << "4. Найти клиента по номеру счета" << endl;
    cout << "5. Записать данные в файл" << endl;
    cout << "6. Прочитать данные из файла" << endl;
    cout << "7. Выйти" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    vector<Client> clients;
    string filename = "clients.txt";
    int choice;

    do {
        displayMenu();
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            Client newClient = inputClient();
            clients.push_back(newClient);
            break;
        }
        case 2: {
            for (const auto& client : clients) {
                printClient(client);
                cout << "-------------------" << endl;
            }
            break;
        }
        case 3: {
            int accountNumber;
            cout << "Введите номер счета для удаления: ";
            cin >> accountNumber;
            deleteClient(clients, accountNumber);
            break;
        }
        case 4: {
            int accountNumber;
            cout << "Введите номер счета для поиска: ";
            cin >> accountNumber;
            findClient(clients, accountNumber);
            break;
        }
        case 5: {
            writeToFile(clients, filename);
            break;
        }
        case 6: {
            readFromFile(clients, filename);
            break;
        }
        case 7: {
            cout << "Выход из программы." << endl;
            break;
        }
        default: {
            cout << "Неверный выбор. Попробуйте снова." << endl;
            break;
        }
        }
    } while (choice != 7);

    return 0;
}