#include <iostream>  
#include <fstream>  
#include <string>  

using namespace std;


int main() {
    setlocale(0, "Rus");
    ifstream inputFile("FILE1.txt");
    ofstream outputFile("FILE2.txt");
    string line;
    int lineNum = 0;

    if (!outputFile.is_open()) {
        cout << "Не удалось открыть файл FILE2!" << endl;
        inputFile.close();
        outputFile.close();
        return 1;

    }

    while (getline(inputFile, line)) {
        lineNum++;
        if (lineNum >= 4) {
            outputFile << line << endl;
        }
    }
    inputFile.close();
    outputFile.close();
    cout << "Копирование завершено!" << endl;
    ifstream word("FILE2.txt");
    string finalWord;
    while (!word.eof()) {
        word >> finalWord;
    }
    word.close();
    cout << finalWord << endl;
    cout << finalWord.length();

    return 0;
}