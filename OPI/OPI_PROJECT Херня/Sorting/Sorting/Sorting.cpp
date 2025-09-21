#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <Windows.h>  // Для установки кодировки консоли

using namespace std;

// Структура для хранения информации о студенте
struct Student {

    string surname;
    int labsPassed;
    int labsToDo;
    string attendedLastLab;  // Сохраняем строку "Да" или "Нет"
    int totalScore;

    // Конструктор для вычисления общего балла
    Student(const string& s, int passed, int toDo, const string& attended)
        : surname(s), labsPassed(passed), labsToDo(toDo), attendedLastLab(attended) {

        // Приводим строку к нижнему регистру и удаляем лишние пробелы
        attendedLastLab = trim(attended);

        // Вычисляем основной балл:
        totalScore = labsPassed + (labsToDo - labsPassed);  // Основной балл за сданные и предстоящие лабораторные

        // Если в attendedLastLab написано "Да", добавляем 10 баллов
        if (attendedLastLab == "Da") {
            totalScore += 10;
        }
    }

    // Функция для удаления пробелов в начале и в конце строки
    static string trim(const string& str) {
        size_t first = str.find_first_not_of(" \t\r\n");
        size_t last = str.find_last_not_of(" \t\r\n");
        if (first == string::npos || last == string::npos)
            return "";  // если строка пуста
        return str.substr(first, last - first + 1);
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

        // Если все данные присутствуют (столбцов 4)
        if (!surname.empty() && !passed.empty() && !toDo.empty() && !attended.empty()) {
            try {
                students.push_back(Student(surname, stoi(passed), stoi(toDo), attended));
            }
            catch (const invalid_argument& e) {
                cerr << "Ошибка при обработке данных студента: " << surname << endl;
            }
        }
        else {
            cerr << "Ошибка: пропущены данные в строке: " << line << endl;
        }
    }

    file.close();
    return students;
}

// Функция для записи студентов в CSV файл
void writeStudentsToFile(const vector<Student>& students, const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла для записи: " << filename << endl;
        return;
    }

    // Записываем заголовок
    file << "Surname,LabsPassed,LabsToDo,AttendedLastLab,TotalScore\n";

    // Записываем данные о студентах
    for (const auto& student : students) {
        file << student.surname << ","
            << student.labsPassed << ","
            << student.labsToDo << ","
            << student.attendedLastLab << ","
            << student.totalScore << "\n";
    }

    file.close();
}

// Функция для вывода студентов
void printStudents(const vector<Student>& students) {
    for (const auto& student : students) {
        cout << student.surname << " "
            << student.labsPassed << " "
            << student.labsToDo << " "
            << student.attendedLastLab << " "
            << student.totalScore << endl; // Выводим общий балл
    }
}

int main() {
    // Устанавливаем кодировку консоли для корректного вывода русских символов
    SetConsoleOutputCP(CP_UTF8); // Устанавливаем кодировку консоли на UTF-8
    SetConsoleCP(CP_UTF8); // Устанавливаем кодировку ввода на UTF-8

    // Указываем путь к CSV файлу
    string filename = "C:\\Уник\\OPI\\OPI_PROJECT\\output.csv";

    // Чтение данных из файла
    vector<Student> students = readDataFromFile(filename);
    if (students.empty()) {
        return 1;
    }

    // Сортировка студентов по общему баллу (по возрастанию)
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.totalScore < b.totalScore;  // Сортируем по возрастанию общего балла
        });

    // Запись отсортированных студентов в новый CSV файл
    string outputFilename = "C:\\Уник\\OPI\\OPI_PROJECT\\sorted_output.csv";
    writeStudentsToFile(students, outputFilename);

    // Вывод отсортированных студентов
    printStudents(students);

    return 0;
}
