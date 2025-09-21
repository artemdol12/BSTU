#include <iostream>
#include <windows.h>
#define STR_LEN 50
#define LIST_SIZE 30

using namespace std;
struct Student {
    char FIO[STR_LEN];
    int exams_number;
    char marks[100];
};
Student list_of_student[LIST_SIZE];
int current_size = 0;
void enter_new();
void del();
void out();
void clear_buffer();
bool isExcellentStudent(const Student& student);
void calculateSuccessRate();

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int choice;
    do {
        cout << "Введите:" << endl;
        cout << "1 - для ввода новой записи" << endl;
        cout << "2 - для вывода записи(ей)" << endl;
        cout << "3 - для удаления записи" << endl;
        cout << "4 - вычислить успеваемость студентов" << endl;
        cout << "5 - для выхода" << endl;
        cin >> choice;
        clear_buffer();
        switch (choice) {
        case 1: enter_new(); break;
        case 2: out(); break;
        case 3: del(); break;
        case 4: calculateSuccessRate(); break;
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
    cout << "ФИО: ";
    cin.getline(list_of_student[current_size].FIO, STR_LEN);
    cout << "Кол-во экзаменов: ";
    cin >> (list_of_student[current_size].exams_number);
    clear_buffer();
    cout << "Оценки: ";
    cin.getline(list_of_student[current_size].marks, 100);
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
            list_of_student[i] = list_of_student[i + 1];
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
            cout << "ФИО: " << list_of_student[n - 1].FIO << endl;
            cout << "Кол-во экзаменов: " << list_of_student[n - 1].exams_number << endl;
            cout << "Оценки: " << list_of_student[n - 1].marks << endl;
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
                cout << "ФИО: " << list_of_student[i].FIO << endl;
                cout << "Кол-во экзаменов: " << list_of_student[i].exams_number << endl;
                cout << "Оценки: " << list_of_student[i].marks << endl;
                cout << "-----------------------------" << endl;
            }
        }
    }
    else {
        cout << "Неверный выбор." << endl;
    }
}
bool isExcellentStudent(const Student& student) {
    int count = 0, negative = 0;
    for (int i = 0; i < student.exams_number * 2; i++) {
        if (student.marks[i] == '1' || student.marks[i] == '2' || student.marks[i] == '3') {
            count++; negative++;
            return false;
        }
        else if (student.marks[i] == '4' || student.marks[i] == '5')
            count++;
        if (count == student.exams_number && negative == 0)
            return true;
    }
    return false;
}
void calculateSuccessRate() {
    if (current_size == 0) {
        cout << "Список студентов пуст." << endl;
        return;
    }

    int excellentStudents = 0;
    for (int i = 0; i < current_size; i++) {
        if (isExcellentStudent(list_of_student[i])) {
            excellentStudents++;
        }
    }

    float successRate = (float)excellentStudents / current_size * 100;
    cout << "Успеваемость студентов: " << successRate << "%" << endl;
}
void clear_buffer() {
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
}