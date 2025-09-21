#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <Windows.h>  // Для установки кодировки консоли

using namespace std;

// Структура для хранения информации о студенте
struct Student {
    string surname;
    int labsPassed;
    int labsToDo;
    bool attendedLastLab;
    int totalScore;

    // Конструктор для вычисления общего балла
    Student(const string& s, int passed, int toDo, const string& attended)
        : surname(s), labsPassed(passed), labsToDo(toDo), attendedLastLab(attended == "Да") {
        totalScore = labsPassed + labsToDo + (attendedLastLab ? 10 : 0);  // Считаем общий балл
    }
};

// Функция для чтения данных из CSV файла
vector<Student> readDataFromFile(const string& filename) {
    vector<Student> students;
    ifstream file(filename);  // Открытие файла с заданным путем

    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла: " << filename << endl;
        return students;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string surname, passed, toDo, attended;

        // Чтение данных из строки
        getline(ss, surname, ',');
        getline(ss, passed, ',');
        getline(ss, toDo, ',');
        getline(ss, attended, ',');

        // Создаем объект Student и добавляем его в список
        students.push_back(Student(surname, stoi(passed), stoi(toDo), attended));
    }

    file.close();
    return students;
}

// Функция для вывода студентов
void printStudents(const vector<Student>& students) {
    for (const auto& student : students) {
        cout << student.surname << ", "
            << student.labsPassed << ", "
            << student.labsToDo << ", "
            << (student.attendedLastLab ? "Да" : "Нет") << endl;
    }
}

int main() {
    // Устанавливаем кодировку консоли для корректного вывода русских символов
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Указываем путь к CSV файлу
    string filename = "C:\\Уник\\OPI\\OPI_PROJECT\\output.csv";

    // Чтение данных из файла
    vector<Student> students = readDataFromFile(filename);
    if (students.empty()) {
        return 1;
    }

    // Сортировка студентов по суммарным баллам
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.totalScore < b.totalScore;  // Сортируем по возрастанию баллов
        });

    // Вывод отсортированных студентов
    printStudents(students);

    return 0;
}
