#include <iostream>
#include <windows.h>
#include <cstring>
#define STR_LEN 50
#define LIST_SIZE 30

using namespace std;

enum Origin {
    PURCHASE,  
    THEFT,     
    GIFT     
};

enum Section {
    SPECIAL_LITERATURE,  
    HOBBY,               
    HOUSEHOLD,           
    FICTION              
};
struct Date {
    unsigned int year : 7;
};

struct Book {
    char author[STR_LEN];
    char title[STR_LEN];
    char publisher[STR_LEN];
    Section section;
    Origin origin;
    bool isAvailable;
    Date publisherYear;
};

Book library[LIST_SIZE];
int current_size = 0;

void enter_new();
void del();
void out();
void search();
void clear_buffer();
const char* getOriginName(Origin origin);
const char* getSectionName(Section section);

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

    cout << "Автор: ";
    cin.getline(library[current_size].author, STR_LEN);

    cout << "Название: ";
    cin.getline(library[current_size].title, STR_LEN);

    cout << "Издательство: ";
    cin.getline(library[current_size].publisher, STR_LEN);

    unsigned int Year;
    while (true) {
        cout << "Год издательства (2000-2127): ";
        cin >> Year;
        if (cin.fail() || Year < 2000 || Year > 2127) { 
            cin.clear();
            clear_buffer();
            cout << "Ошибка! Введите год от 2000 до 2127." << endl;
        }
        else {
            clear_buffer();
            break;
        }
    }
    library[current_size].publisherYear.year = Year - 2000; 

    int section;
    cout << "Раздел (0 - Специальная литература, 1 - Хобби, 2 - Домашнее хозяйство, 3 - Беллетристика): ";
    cin >> section;
    library[current_size].section = static_cast<Section>(section);

    int origin;
    cout << "Происхождение (0 - Покупка, 1 - Кража, 2 - Подарок): ";
    cin >> origin;
    library[current_size].origin = static_cast<Origin>(origin);

    cout << "Наличие книги (1 - есть, 0 - нет): ";
    cin >> library[current_size].isAvailable;
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
            library[i] = library[i + 1];
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
            cout << "Автор: " << library[n - 1].author << endl;
            cout << "Название: " << library[n - 1].title << endl;
            cout << "Издательство: " << library[n - 1].publisher << endl;
            cout << "Раздел: " << getSectionName(library[n - 1].section) << endl;
            cout << "Происхождение: " << getOriginName(library[n - 1].origin) << endl;
            cout << "Наличие: " << (library[n - 1].isAvailable ? "Есть" : "Нет") << endl;
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
                cout << "Автор: " << library[i].author << endl;
                cout << "Название: " << library[i].title << endl;
                cout << "Издательство: " << library[i].publisher << endl;
                cout << "Раздел: " << getSectionName(library[i].section) << endl;
                cout << "Происхождение: " << getOriginName(library[i].origin) << endl;
                cout << "Наличие: " << (library[i].isAvailable ? "Есть" : "Нет") << endl;
                cout << "-----------------------------" << endl;
            }
        }
    }
    else {
        cout << "Неверный выбор." << endl;
    }
}

void search() {
    unsigned int searchYear;
    cout << "Введите год издания для поиска: ";
    cin >> searchYear;
    clear_buffer();

    bool found = false;
    for (int i = 0; i < current_size; i++) {
        unsigned int bookYear = library[i].publisherYear.year + 2000;
        if (bookYear == searchYear) {
            cout << "Найдено:" << endl;
            cout << "Автор: " << library[i].author << endl;
            cout << "Название: " << library[i].title << endl;
            cout << "Издательство: " << library[i].publisher << endl;
            cout << "Год издания: " << bookYear << endl;
            cout << "Раздел: " << getSectionName(library[i].section) << endl;
            cout << "Происхождение: " << getOriginName(library[i].origin) << endl;
            cout << "Наличие: " << (library[i].isAvailable ? "Есть" : "Нет") << endl;
            cout << "-----------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Книги с годом издания " << searchYear << " не найдены." << endl;
    }
}

const char* getOriginName(Origin origin) {
    switch (origin) {
    case PURCHASE: return "Покупка";
    case THEFT: return "Кража";
    case GIFT: return "Подарок";
    default: return "Неизвестно";
    }
}

const char* getSectionName(Section section) {
    switch (section) {
    case SPECIAL_LITERATURE: return "Специальная литература";
    case HOBBY: return "Хобби";
    case HOUSEHOLD: return "Домашнее хозяйство";
    case FICTION: return "Беллетристика";
    default: return "Неизвестно";
    }
}

void clear_buffer() {
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
}