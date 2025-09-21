#include <iostream>
#include <fstream>
#include <cstring>
#include <Windows.h>
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

union OriginDetails {
    char purchaseDate[STR_LEN];  
    char theftLocation[STR_LEN]; 
    char giverName[STR_LEN];     
};

struct Book {
    char author[STR_LEN];
    char title[STR_LEN];
    char publisher[STR_LEN];
    Section section;
    Origin origin;
    OriginDetails originDetails;
    bool isAvailable;
};

Book library[LIST_SIZE];
int current_size = 0;

void enter_new();
void del();
void out();
void search();
void saveToFile();
void loadFromFile();
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
    cout << "Автор: ";
    cin.getline(library[current_size].author, STR_LEN);
    cout << "Название: ";
    cin.getline(library[current_size].title, STR_LEN);
    cout << "Издательство: ";
    cin.getline(library[current_size].publisher, STR_LEN);

    int section;
    cout << "Раздел (0 - Специальная литература, 1 - Хобби, 2 - Домашнее хозяйство, 3 - Беллетристика): ";
    cin >> section;
    library[current_size].section = static_cast<Section>(section);

    int origin;
    cout << "Происхождение (0 - Покупка, 1 - Кража, 2 - Подарок): ";
    cin >> origin;
    library[current_size].origin = static_cast<Origin>(origin);
    clear_buffer();

    switch (library[current_size].origin) {
    case PURCHASE:
        cout << "Дата покупки: ";
        cin.getline(library[current_size].originDetails.purchaseDate, STR_LEN);
        break;
    case THEFT:
        cout << "Место кражи: ";
        cin.getline(library[current_size].originDetails.theftLocation, STR_LEN);
        break;
    case GIFT:
        cout << "Имя дарителя: ";
        cin.getline(library[current_size].originDetails.giverName, STR_LEN);
        break;
    }

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
            switch (library[n - 1].origin) {
            case PURCHASE:
                cout << "Дата покупки: " << library[n - 1].originDetails.purchaseDate << endl;
                break;
            case THEFT:
                cout << "Место кражи: " << library[n - 1].originDetails.theftLocation << endl;
                break;
            case GIFT:
                cout << "Имя дарителя: " << library[n - 1].originDetails.giverName << endl;
                break;
            }
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
                switch (library[i].origin) {
                case PURCHASE:
                    cout << "Дата покупки: " << library[i].originDetails.purchaseDate << endl;
                    break;
                case THEFT:
                    cout << "Место кражи: " << library[i].originDetails.theftLocation << endl;
                    break;
                case GIFT:
                    cout << "Имя дарителя: " << library[i].originDetails.giverName << endl;
                    break;
                }
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
    char query[STR_LEN];
    cout << "Введите автора для поиска: ";
    cin.getline(query, STR_LEN);
    bool found = false;
    for (int i = 0; i < current_size; i++) {
        if (strstr(library[i].author, query) != nullptr) {
            cout << "Найдено:" << endl;
            cout << "Автор: " << library[i].author << endl;
            cout << "Название: " << library[i].title << endl;
            cout << "Издательство: " << library[i].publisher << endl;
            cout << "Раздел: " << getSectionName(library[i].section) << endl;
            cout << "Происхождение: " << getOriginName(library[i].origin) << endl;
            switch (library[i].origin) {
            case PURCHASE:
                cout << "Дата покупки: " << library[i].originDetails.purchaseDate << endl;
                break;
            case THEFT:
                cout << "Место кражи: " << library[i].originDetails.theftLocation << endl;
                break;
            case GIFT:
                cout << "Имя дарителя: " << library[i].originDetails.giverName << endl;
                break;
            }
            cout << "Наличие: " << (library[i].isAvailable ? "Есть" : "Нет") << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Ничего не найдено." << endl;
    }
}

void saveToFile() {
    ofstream file("library.dat", ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    file.write((char*)&library, sizeof(library));
    file.close();
    cout << "Данные сохранены в файл." << endl;
}

void loadFromFile() {
    ifstream file("library.dat", ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    file.read((char*)&library, sizeof(library));
    file.close();
    cout << "Данные загружены из файла." << endl;
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