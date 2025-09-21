#include <iostream>
#include <windows.h>
#include <cstring>
#define STR_LEN 50
#define LIST_SIZE 8

using namespace std;
struct TRAIN {
    char destination[STR_LEN];
    char train_number[100];
    char departure_time[6];
};
TRAIN list_of_trains[LIST_SIZE];
int current_size = 0;
void enter_new();
void del();
void out();
void clear_buffer();
void sortTrainsByDestination();
void findTrainsAfterTime(const char* time);

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int choice;
    do {
        cout << "Введите:" << endl;
        cout << "1 - для ввода новой записи" << endl;
        cout << "2 - для вывода записи(ей)" << endl;
        cout << "3 - для удаления записи" << endl;
        cout << "4 - для поиска поездов после указанного времени" << endl;
        cout << "5 - для выхода" << endl;
        cin >> choice;
        clear_buffer();
        switch (choice) {
        case 1: enter_new(); break;
        case 2: out(); break;
        case 3: del(); break;
        case 4: {
            char time[6];
            cout << "Введите время отправления (формат ЧЧ:ММ): ";
            cin.getline(time, 6);
            findTrainsAfterTime(time);
            break;
        }
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
    cout << "Пункт назначения: ";
    cin.getline(list_of_trains[current_size].destination, STR_LEN);
    cout << "Номер поезда: ";
    cin.getline(list_of_trains[current_size].train_number, 100);
    clear_buffer();
    cout << "Время отправления (формат ЧЧ:ММ): ";
    cin.getline(list_of_trains[current_size].departure_time, 6);
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
            list_of_trains[i] = list_of_trains[i + 1];
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
            cout << "Пункт назначения: " << list_of_trains[n - 1].destination << endl;
            cout << "Номер поезда: " << list_of_trains[n - 1].train_number << endl;
            cout << "Время отправления: " << list_of_trains[n - 1].departure_time << endl;
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
            sortTrainsByDestination();
            for (int i = 0; i < current_size; i++) {
                cout << "Запись №" << i + 1 << ":" << endl;
                cout << "Пункт назначения: " << list_of_trains[i].destination << endl;
                cout << "Номер поезда: " << list_of_trains[i].train_number << endl;
                cout << "Время отправления: " << list_of_trains[i].departure_time << endl;
                cout << "-----------------------------" << endl;
            }
        }
    }
    else {
        cout << "Неверный выбор." << endl;
    }
}
void sortTrainsByDestination() {
    for (int i = 0; i < current_size - 1; i++) {
        for (int j = i + 1; j < current_size; j++) {
            if (strcmp(list_of_trains[i].destination, list_of_trains[j].destination) > 0) {
                TRAIN temp = list_of_trains[i];
                list_of_trains[i] = list_of_trains[j];
                list_of_trains[j] = temp;
            }
        }
    }
}
void findTrainsAfterTime(const char* time) {
    sortTrainsByDestination();
    bool found = false;
    cout << "Поезда, отправляющиеся после " << time << ":" << endl;
    for (int i = 0; i < current_size; i++) {
        if (strcmp(list_of_trains[i].departure_time, time) > 0) {
            cout << "Пункт назначения: " << list_of_trains[i].destination << endl;
            cout << "Номер поезда: " << list_of_trains[i].train_number << endl;
            cout << "Время отправления: " << list_of_trains[i].departure_time << endl;
            cout << "-----------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Поездов, отправляющихся после " << time << ", не найдено." << endl;
    }
}
void clear_buffer() {
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
}