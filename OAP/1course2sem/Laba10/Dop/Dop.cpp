#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void generateNumbers(int A, ofstream& file, string current = "") {
    if (current.length() == A) {
        file << current << endl;
        return;
    }
    for (int i = 0; i <= A; ++i) {
        generateNumbers(A, file, current + to_string(i));
    }
}

void task1() {
    int A;
    cout << "Введите A: ";
    cin >> A;
    ofstream file("numbers.txt");
    if (file.is_open()) {
        generateNumbers(A, file);
        file.close();
        cout << "Числа записаны в файл 'numbers.txt'." << endl;
    }
    else {
        cerr << "Ошибка открытия файла!" << endl;
    }
}
void task2() {
    int numbers[] = { 1, 2, 3, 4, 5 };
    sort(numbers, numbers + 5);
    cout << "Все перестановки:" << endl;
    do {
        for (int num : numbers) cout << num << " ";
        cout << endl;
    } while (next_permutation(numbers, numbers + 5));
}

void showMenu() {
    cout << "\nМеню:\n";
    cout << "1. Задание 1 (генерация чисел)\n";
    cout << "2. Задание 2 (перестановки)\n";
    cout << "0. Выход\n";
    cout << "Выберите задание: ";
}

int main() {
    setlocale(LC_ALL, "rus");
    int choice;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 0: cout << "Выход...\n"; break;
        default: cout << "Неверный выбор!\n";
        }
    } while (choice != 0);

    return 0;
}