#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>

using namespace std;
void writeToFile(const string& filename, const string& data) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << filename << endl;
        exit(1);
    }
    outputFile << data;
    outputFile.close();
    cout << "Данные записаны в файл!" << endl;
}

string readFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << filename << "!" << endl;
        exit(1);
    }
    string data;
    getline(inputFile, data);
    inputFile.close();
    return data;
}

string findIntegerSubstring(const string& str) {
    string tempNum;
    string result;
    for (size_t i = 0; i < str.length(); i++) {
        char ch = str[i];

        if (isdigit(ch) || (ch == '-' && tempNum.empty()) || (ch == '+' && tempNum.empty())) {
            tempNum += ch;
        }
        else {
           
            if (!tempNum.empty() && (tempNum != "+" && tempNum != "-")) {
                result = tempNum; 
                break; 
            }
            tempNum.clear();
        }
    }
    if (!tempNum.empty() && (tempNum != "+" && tempNum != "-")) {
        result = tempNum;
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string userInput;
    cout << "Введите строку, которая содержит буквы, цифры, запятые, точки, знаки + и -: ";
    getline(cin, userInput);
    writeToFile("FILE3.txt", userInput);
    string fileContent = readFromFile("FILE3.txt");
    string integerSubstring = findIntegerSubstring(fileContent);

    if (!integerSubstring.empty()) {
        cout << "Найдено целое число: " << integerSubstring << endl;
    }
    else {
        cout << "Целые числа не найдены в строке." << endl;
    }
    return 0;
}