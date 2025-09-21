#include <iostream>
using namespace std;

void codeCheckAm() { // Функция хуйни переименовать все фунции
    unsigned char capitalLetter = ' ', lowercaseLetter = ' ';
    cout << "Введите вторую букву фамилии на английском прописной: ";
    cin >> capitalLetter;
    cout << "Введите вторую букву фамилии на английском строчной: ";
    cin >> lowercaseLetter;

    if (int(lowercaseLetter) - int(capitalLetter) == 32) {
        cout << "Разница значений кодов: " << (int)capitalLetter - (int)lowercaseLetter << endl;
    }
    else {
        cout << "Ошибка (Введите, что просится)" << endl;
    }
}

void codeCheckRu() {
    unsigned char capitalLetterRU = ' ', lowercaseLetterRU = ' ';
    cout << "Введите вторую букву имени на русском языке прописной: ";
    cin >> capitalLetterRU;
    cout << "Введите вторую букву имени на русском языке строчной: ";
    cin >> lowercaseLetterRU;

    if (int(capitalLetterRU) - int(lowercaseLetterRU) == -32) {
        cout << "Разница значений кодов: " << (int)capitalLetterRU - (int)lowercaseLetterRU << endl;
    }
    else {
        cout << "Ошибка (Введите, что просится)" << endl;
    }
}

void codeCheckNu() {
    unsigned char nameLength = ' ';
    cout << "Введите число (кол-во букв в фамилии): ";
    cin >> nameLength;
    cout << "Код числа: " << (int)nameLength << endl;
}

void selectAction(int choice) {
    switch (choice) {
    case 1: codeCheckAm(); break;
    case 2: codeCheckRu(); break;
    case 3: codeCheckNu(); break;
    case 4: cout << "Выход из программы." << endl; exit(0);
    default: cout << "Некорректный вариант" << endl; break;
    }
}
