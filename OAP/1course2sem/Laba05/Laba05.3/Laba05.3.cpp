#include <iostream>
#include <windows.h>
#include <cstring>
#define STR_LEN 50
#define LIST_SIZE 30

using namespace std;

enum Day {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

struct Time {
    unsigned int hours : 5;   
    unsigned int minutes : 6; 
};

struct Train {
    int number;
    char destination[STR_LEN];
    Day day;
    Time arrival;
    Time departure;
};

Train station[LIST_SIZE];
int current_size = 0;

void enter_new();
void del();
void out();
void search();
void clear_buffer();
const char* getDayName(Day day);

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
    cout << "Номер поезда: ";
    cin >> station[current_size].number;
    clear_buffer();
    cout << "Пункт назначения: ";
    cin.getline(station[current_size].destination, STR_LEN);

    int day;
    cout << "День следования (0 - ПН, 1 - ВТ, 2 - СР, 3 - ЧТ, 4 - ПТ, 5 - СБ, 6 - ВС): ";
    cin >> day;
    station[current_size].day = static_cast<Day>(day);

    cout << "Время прибытия (часы минуты): ";
    unsigned int hours, minutes;
    cin >> hours >> minutes;
    station[current_size].arrival = { hours, minutes };

    cout << "Время отправления (часы минуты): ";
    cin >> hours >> minutes;
    station[current_size].departure = { hours, minutes };
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
            station[i] = station[i + 1];
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
            cout << "Номер поезда: " << station[n - 1].number << endl;
            cout << "Пункт назначения: " << station[n - 1].destination << endl;
            cout << "День следования: " << getDayName(station[n - 1].day) << endl;
            cout << "Время прибытия: " << station[n - 1].arrival.hours << ":" << station[n - 1].arrival.minutes << endl;
            cout << "Время отправления: " << station[n - 1].departure.hours << ":" << station[n - 1].departure.minutes << endl;
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
                cout << "Номер поезда: " << station[i].number << endl;
                cout << "Пункт назначения: " << station[i].destination << endl;
                cout << "День следования: " << getDayName(station[i].day) << endl;
                cout << "Время прибытия: " << station[i].arrival.hours << ":" << station[i].arrival.minutes << endl;
                cout << "Время отправления: " << station[i].departure.hours << ":" << station[i].departure.minutes << endl;
                cout << "-----------------------------" << endl;
            }
        }
    }
    else {
        cout << "Неверный выбор." << endl;
    }
}

void search() {
    char destination[STR_LEN];
    cout << "Введите пункт назначения для поиска: ";
    cin.getline(destination, STR_LEN);
    bool found = false;
    for (int i = 0; i < current_size; i++) {
        if (strstr(station[i].destination, destination) != nullptr) {
            cout << "Найдено:" << endl;
            cout << "Номер поезда: " << station[i].number << endl;
            cout << "Пункт назначения: " << station[i].destination << endl;
            cout << "День следования: " << getDayName(station[i].day) << endl;
            cout << "Время прибытия: " << station[i].arrival.hours << ":" << station[i].arrival.minutes << endl;
            cout << "Время отправления: " << station[i].departure.hours << ":" << station[i].departure.minutes << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Ничего не найдено." << endl;
    }
}

const char* getDayName(Day day) {
    switch (day) {
    case MONDAY: return "Понедельник";
    case TUESDAY: return "Вторник";
    case WEDNESDAY: return "Среда";
    case THURSDAY: return "Четверг";
    case FRIDAY: return "Пятница";
    case SATURDAY: return "Суббота";
    case SUNDAY: return "Воскресенье";
    default: return "Неизвестно";
    }
}

void clear_buffer() {
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
}