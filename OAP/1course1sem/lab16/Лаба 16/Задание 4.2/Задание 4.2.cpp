#include <iostream>
#include <string>
using namespace std;

// Функция для подсчета вхождений символа в строке
int countOccurrences(const string& str, char ch) {
    int count = 0;
    for (char c : str) {
        if (c == ch) {
            count++;
        }
    }
    return count;
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    int n;
    cout << "Введите количество строк текста: ";
    cin >> n;
    cin.ignore();  // Игнорируем символ новой строки после ввода числа

    string text;
    char symbol;
    int totalCount = 0;

    // Вводим символ для подсчета
    cout << "Введите символ для подсчета вхождений: ";
    cin >> symbol;
    cin.ignore();  // Чтобы избежать проблем с символом новой строки после ввода символа

    // Вводим строки
    cout << "Введите " << n << " строк текста:\n";
    for (int i = 0; i < n; ++i) {
        getline(cin, text);  // Чтение каждой строки
        totalCount += countOccurrences(text, symbol);  // Подсчитываем вхождения символа
    }

    // Подсчитываем и выводим количество вхождений
    cout << "Суммарное количество вхождений символа '" << symbol << "': " << totalCount << endl;

    return 0;
}
