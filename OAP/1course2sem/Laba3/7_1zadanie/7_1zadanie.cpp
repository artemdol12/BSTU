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

    while (file_one.getline(str, 1000)) {
        bool isSingleWord = true;

        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == ' ') {
                isSingleWord = false;
                break;
            }
        }

        if (isSingleWord && str[0] != '\0') {
            file_two << str << endl;
        }
    }
    file_one.close();
    file_two.close();
    cout << "Данные успешно скопированы" << endl;

    ifstream file_three("FILE2.txt");
    if (!file_three) {
        cout << "Файл не открывается" << endl;
        return 1;
    }

    while (file_three.getline(str, 1000)) {
        if (strlen(str) == 5) {
            cout << "Найдено 5-символьное слово: " << str << endl;
            file_three.close();
            return 0;
        }
    }
    cout << "нету 5-символьного слово" << endl;
    file_three.close();
    return 0;
}
