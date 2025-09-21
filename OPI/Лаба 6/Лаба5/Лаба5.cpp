#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    SetConsoleCP(1251);
    int choice;
    string xB, xS, yB, yS;
    char z;
    int k;

    puts("Какое действие хотите использовать?(1, 2, 3, 4)");
    cin >> k;

    switch (k)
    {
    case 1: {
        cout << "Введите буквы на английском (прописной и строчной): ";
        cin >> xB >> xS;

        if (xB.length() == xS.length()) {
            for (size_t i = 0; i < xB.length(); ++i) {
                int code = int(xS[i]) - int(xB[i]);
                cout << "Разница значений кодов для '" << xB[i] << "' и '" << xS[i] << "': " << code << endl;
            }
        }
        else {
            cout << "Ошибка: строки должны быть одной длины." << endl;
        }
        break;
    }
    case 2: {
        cout << "Введите буквы на русском (прописной и строчной): ";
        cin >> yB >> yS;

        if (yB.length() == yS.length()) {
            for (size_t i = 0; i < yB.length(); ++i) {
                int code = int(yB[i]) - int(yS[i]);
                cout << "Разница значений кодов для '" << yB[i] << "' и '" << yS[i] << "': " << code << endl;
            }
        }
        else {
            cout << "Ошибка: строки должны быть одной длины." << endl;
        }
        break;
    }
    case 3: {
        cout << "Введите число (кол-во букв в фамилии): ";
        cin >> z;
        cout << "Код числа: " << (int)z << endl;
        break;
    }
    case 4: {
        cout << "Выход из программы." << endl;
        return 0;
    }
    default: {
        puts("Некорректный вариант");
        break;
    }
    }

    return 0;
}
