#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

enum Subject { MATH, PHYSICS, CHEMISTRY, LITERATURE, BIOLOGY, SUBJECT_COUNT };

struct ClassInfo {
    unsigned int number : 4;
    unsigned int letter : 5;
};

struct Student {
    string lastName;
    string firstName;
    string middleName;
    ClassInfo classInfo;
    int grades[SUBJECT_COUNT];
    float average;
};

vector<Student> students;

void inputStudent(Student& s) {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "Фамилия: "; cin >> s.lastName;
    cout << "Имя: "; cin >> s.firstName;
    cout << "Отчество: "; cin >> s.middleName;

    unsigned num;
    cout << "Класс (цифра): "; cin >> num;
    s.classInfo.number = num;

    char letter;
    cout << "Класс (буква): "; cin >> letter;
    s.classInfo.letter = toupper(letter) - 'A' + 1;

    cout << "Оценки по предметам (MATH, PHYSICS, CHEMISTRY, LITERATURE, BIOLOGY):\n";
    for (int i = 0; i < SUBJECT_COUNT; ++i) { // Ввод оценок 
        cout << "Оценка " << i + 1 << ": ";
        cin >> s.grades[i];
    }

    float sum = 0;
    for (int g : s.grades) sum += g; // Под счет суммы
    s.average = sum / SUBJECT_COUNT; // Средний
}

void printStudent(const Student& s) {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "\nФИО: " << s.lastName << " " << s.firstName << " " << s.middleName
        << "\nКласс: " << s.classInfo.number << char('A' + s.classInfo.letter - 1)
        << "\nОценки: ";
    for (int g : s.grades) cout << g << " ";
    cout << "\nСредний: " << s.average << "\n";
}

void deleteByLastName(const string& lastName) {
    students.erase(remove_if(students.begin(), students.end(),
        [&](const Student& s) { return s.lastName == lastName; }),
        students.end());
}

void searchByLastName(const string& lastName) {
    for (const auto& s : students)
        if (s.lastName == lastName)
            printStudent(s);
}

void menu() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int choice;
    string lastName;
    Student s;

    do {
        cout << "\n1. Добавить\n2. Вывести\n3. Удалить\n4. Найти\n5. Выход\nВыбор: ";
        cin >> choice;
        switch (choice) {
        case 1: inputStudent(s); students.push_back(s); break;
        case 2: for (const auto& s : students) printStudent(s); break;
        case 3: cout << "Фамилия: "; cin >> lastName; deleteByLastName(lastName); break;
        case 4: cout << "Фамилия: "; cin >> lastName; searchByLastName(lastName); break;
        }
    } while (choice != 5);
}

int main() {
    menu();
}