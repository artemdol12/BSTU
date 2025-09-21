#include <stdio.h>
#include <iostream>
#include <cctype>

void main() {
    char s[256];
    int i;
    using namespace std;

    setlocale(LC_CTYPE, "Russian");

    puts("Введите строку: ");
    gets_s(s);

    cout << "Найденные целые числа: " << endl;

    for (i = 0; s[i] != 0; i++) {
        if (isdigit(s[i]) || s[i] == '+' || s[i] == '-') {
            int start = i;
            while (isdigit(s[i]) || s[i] == '+' || s[i] == '-') {
                i++;
            }
            for (int j = start; j < i; j++) {
                cout << s[j];
            }
            cout << endl;
        }
    }
}
