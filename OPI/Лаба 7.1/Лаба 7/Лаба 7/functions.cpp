#include <iostream>
using namespace std;

void codeCheckAm() { // ������� ����� ������������� ��� ������
    unsigned char capitalLetter = ' ', lowercaseLetter = ' ';
    cout << "������� ������ ����� ������� �� ���������� ���������: ";
    cin >> capitalLetter;
    cout << "������� ������ ����� ������� �� ���������� ��������: ";
    cin >> lowercaseLetter;

    if (int(lowercaseLetter) - int(capitalLetter) == 32) {
        cout << "������� �������� �����: " << (int)capitalLetter - (int)lowercaseLetter << endl;
    }
    else {
        cout << "������ (�������, ��� ��������)" << endl;
    }
}

void codeCheckRu() {
    unsigned char capitalLetterRU = ' ', lowercaseLetterRU = ' ';
    cout << "������� ������ ����� ����� �� ������� ����� ���������: ";
    cin >> capitalLetterRU;
    cout << "������� ������ ����� ����� �� ������� ����� ��������: ";
    cin >> lowercaseLetterRU;

    if (int(capitalLetterRU) - int(lowercaseLetterRU) == -32) {
        cout << "������� �������� �����: " << (int)capitalLetterRU - (int)lowercaseLetterRU << endl;
    }
    else {
        cout << "������ (�������, ��� ��������)" << endl;
    }
}

void codeCheckNu() {
    unsigned char nameLength = ' ';
    cout << "������� ����� (���-�� ���� � �������): ";
    cin >> nameLength;
    cout << "��� �����: " << (int)nameLength << endl;
}

void selectAction(int choice) {
    switch (choice) {
    case 1: codeCheckAm(); break;
    case 2: codeCheckRu(); break;
    case 3: codeCheckNu(); break;
    case 4: cout << "����� �� ���������." << endl; exit(0);
    default: cout << "������������ �������" << endl; break;
    }
}
