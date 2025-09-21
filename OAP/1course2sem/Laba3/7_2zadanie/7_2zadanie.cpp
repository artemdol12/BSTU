#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>  

using namespace std;

int writeToFile(const string& filename, const string& data) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cout << "Не удалось открыть файл!" << endl;
        return 1;
    }
    outputFile << data;
    outputFile.close();
    cout << "Информация успешно записана в файл!" << endl;
    return 0;
}

string readFromFile(const string& filename) {
    ifstream readfile(filename);
    if (!readfile.is_open()) {
        cout << "Ошибка чтения файла!" << endl;
        return "1";
    }
    string data;
    getline(readfile, data);
    readfile.close();
    return data;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    string fileContent = readFromFile("FILE3.txt");

    int wordNumber = 1;
    int charCount = 1;
    bool found = false;
    char ch[100];
    cout << "Введите с клавиатуры строку, состоящую из цифр и слов, с пробелами:" << endl;
    cin.getline(ch, 100);

    writeToFile("FILE3.txt", ch);

    cout << "Введите значение k: ";
    int k;
    cin >> k;

    for (char c : fileContent) {
        if (c == ' ') {
            wordNumber++;
            if (charCount + 1 == k) {
                cout << "В k-й позиции содержится пробел, номер предыдущего слова: " << wordNumber - 1 << endl;
                found = true;
                break;
            }
        }
        else {
            charCount++;
            if (charCount == k) {
                cout << "Номер слова, содержащего " << k << "-й символ: " << wordNumber << endl;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "В строке нет достаточно символов для заданной позиции." << endl;
    }
    return 0;
}