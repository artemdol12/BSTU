#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    char str[1000];
    ifstream file_one("FILE1.txt");
    ofstream file_two("FILE2.txt");
    if (!file_one) {
        cout << "Файл не открыт FILE1 для чтения" << endl;
        return 1;
    }
    if (!file_two) {
        cout << "Файл не открыт FILE2 для записи" << endl;
        return 1;
    }
    int N1, N2;
    cout << "Введите диапазон строк (N1 и N2): ";
    cin >> N1 >> N2;

    int lineNum = 1;
    bool firstLineCopied = false;
    int wordCount = 0;

    while (file_one.getline(str, 1000)) {
        if (lineNum >= N1 && lineNum <= N2) {
            if (str[0] == 'C' || str[0] == 'С') {
                file_two << str << endl;

                if (!firstLineCopied) {
                    firstLineCopied = true;
                    wordCount = 1;
                    for (int i = 0; str[i] != '\0'; i++) {
                        if (str[i] == ' ') {
                            wordCount++;
                        }
                    }
                }
            }
        }
        lineNum++;
    }

    file_one.close();
    file_two.close();
    if (firstLineCopied) {
        cout << "Данные успешно скопированы." << endl;
        cout << "Количество слов в первой строке FILE2: " << wordCount << endl;
    }
    else {
        cout << "В указанном диапазоне строк, начинающихся на 'C' или 'С', не найдено." << endl;
    }
}
