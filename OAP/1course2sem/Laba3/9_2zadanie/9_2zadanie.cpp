#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <climits>

using namespace std;

void writeToFile(const string& filename, const string& data) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cout << "Ошибка открытия файла для записи!" << endl;
        exit(1);
    }
    outputFile << data;
    outputFile.close();
    cout << "Данные успешно записаны в файл!" << endl;
}

string readFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Ошибка открытия файла для чтения!" << endl;
        exit(1);
    }
    string data;
    getline(inputFile, data);
    inputFile.close();
    return data;
}

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string userInput;
    cout << "Введите с клавиатуры строку символов, состоящую из слов, разделенных пробелами:" << endl;
    getline(cin, userInput);
    writeToFile("FILE3.txt", userInput);
    string fileContent = readFromFile("FILE3.txt");

    int words = 1;         
    int wordNum = 1;       
    int length = 0;        
    int minLength = INT_MAX;

    for (size_t i = 0; i < fileContent.length(); i++) {
        if (fileContent[i] != ' ') {
            length++;
        }
        else {
            if (length < minLength) {
                minLength = length;
                wordNum = words;
            }
            length = 0;
            words++;
        }
    }

    if (length < minLength) {
        minLength = length;
        wordNum = words;
    }
    cout << "Порядковый номер слова минимальной длины: " << wordNum << endl;
    cout << "Количество символов в слове: " << minLength << endl;

    return 0;
}