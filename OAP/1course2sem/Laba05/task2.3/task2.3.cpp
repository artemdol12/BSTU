#include <iostream>
#include <fstream>
#include <cstring>
#include <Windows.h>
#define STR_LEN 50
#define LIST_SIZE 30

using namespace std;

enum Subject {
    MATH,
    PHYSICS,
    CHEMISTRY,
    LITERATURE,
    BIOLOGY,
    SUBJECT_COUNT
};

union StudentDetails {
    char parentName[STR_LEN];  
    char address[STR_LEN];    
};

struct Student {
    char lastName[STR_LEN];
    char firstName[STR_LEN];
    char middleName[STR_LEN];
    int classNumber;
    char classLetter;
    int grades[SUBJECT_COUNT];
    float average;
    StudentDetails details;
};

Student students[LIST_SIZE];
int current_size = 0;

void enter_new();
void del();
void out();
void search();
void saveToFile();
void loadFromFile();
void clear_buffer();
const char* getSubjectName(Subject subject);

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
    cout << "Фамилия: ";
    cin.getline(students[current_size].lastName, STR_LEN);
    cout << "Имя: ";
    cin.getline(students[current_size].firstName, STR_LEN);
    cout << "Отчество: ";
    cin.getline(students[current_size].middleName, STR_LEN);
    cout << "Класс (цифра): ";
    cin >> students[current_size].classNumber;
    cout << "Класс (буква): ";
    cin >> students[current_size].classLetter;
    clear_buffer();

    cout << "Оценки по предметам (MATH, PHYSICS, CHEMISTRY, LITERATURE, BIOLOGY):\n";
    for (int i = 0; i < SUBJECT_COUNT; i++) {
        cout << "Оценка " << getSubjectName(static_cast<Subject>(i)) << ": ";
        cin >> students[current_size].grades[i];
    }

    cout << "Дополнительная информация (1 - Имя родителя, 2 - Адрес): ";
    int detailChoice;
    cin >> detailChoice;
    clear_buffer();
    switch (detailChoice) {
    case 1:
        cout << "Имя родителя: ";
        cin.getline(students[current_size].details.parentName, STR_LEN);
        break;
    case 2:
        cout << "Адрес: ";
        cin.getline(students[current_size].details.address, STR_LEN);
        break;
    default:
        cout << "Неверный выбор. Дополнительная информация не добавлена." << endl;
        break;
    }

    float sum = 0;
    for (int i = 0; i < SUBJECT_COUNT; i++) {
        sum += students[current_size].grades[i];
    }
    students[current_size].average = sum / SUBJECT_COUNT;

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
            students[i] = students[i + 1];
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
            cout << "ФИО: " << students[n - 1].lastName << " " << students[n - 1].firstName << " " << students[n - 1].middleName << endl;
            cout << "Класс: " << students[n - 1].classNumber << students[n - 1].classLetter << endl;
            cout << "Оценки: ";
            for (int i = 0; i < SUBJECT_COUNT; i++) {
                cout << getSubjectName(static_cast<Subject>(i)) << ": " << students[n - 1].grades[i] << " ";
            }
            cout << endl;
            cout << "Средний балл: " << students[n - 1].average << endl;
            cout << "Дополнительная информация: ";
            if (strlen(students[n - 1].details.parentName)) {
                cout << "Имя родителя: " << students[n - 1].details.parentName << endl;
            }
            else if (strlen(students[n - 1].details.address)) {
                cout << "Адрес: " << students[n - 1].details.address << endl;
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
                cout << "ФИО: " << students[i].lastName << " " << students[i].firstName << " " << students[i].middleName << endl;
                cout << "Класс: " << students[i].classNumber << students[i].classLetter << endl;
                cout << "Оценки: ";
                for (int j = 0; j < SUBJECT_COUNT; j++) {
                    cout << getSubjectName(static_cast<Subject>(j)) << ": " << students[i].grades[j] << " ";
                }
                cout << endl;
                cout << "Средний балл: " << students[i].average << endl;
                cout << "Дополнительная информация: ";
                if (strlen(students[i].details.parentName)) {
                    cout << "Имя родителя: " << students[i].details.parentName << endl;
                }
                else if (strlen(students[i].details.address)) {
                    cout << "Адрес: " << students[i].details.address << endl;
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
    cout << "Введите фамилию для поиска: ";
    cin.getline(query, STR_LEN);
    bool found = false;
    for (int i = 0; i < current_size; i++) {
        if (strstr(students[i].lastName, query) != nullptr) {
            cout << "Найдено:" << endl;
            cout << "ФИО: " << students[i].lastName << " " << students[i].firstName << " " << students[i].middleName << endl;
            cout << "Класс: " << students[i].classNumber << students[i].classLetter << endl;
            cout << "Оценки: ";
            for (int j = 0; j < SUBJECT_COUNT; j++) {
                cout << getSubjectName(static_cast<Subject>(j)) << ": " << students[i].grades[j] << " ";
            }
            cout << endl;
            cout << "Средний балл: " << students[i].average << endl;
            cout << "Дополнительная информация: ";
            if (strlen(students[i].details.parentName)) {
                cout << "Имя родителя: " << students[i].details.parentName << endl;
            }
            else if (strlen(students[i].details.address)) {
                cout << "Адрес: " << students[i].details.address << endl;
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
    ofstream file("students.dat", ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    file.write((char*)&students, sizeof(students));
    file.close();
    cout << "Данные сохранены в файл." << endl;
}

void loadFromFile() {
    ifstream file("students.dat", ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    file.read((char*)&students, sizeof(students));
    file.close();
    cout << "Данные загружены из файла." << endl;
}

const char* getSubjectName(Subject subject) {
    switch (subject) {
    case MATH: return "Математика";
    case PHYSICS: return "Физика";
    case CHEMISTRY: return "Химия";
    case LITERATURE: return "Литература";
    case BIOLOGY: return "Биология";
    default: return "Неизвестно";
    }
}

void clear_buffer() {
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
}