#include <iostream>
#include <Windows.h>
#include "functions.h"

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    SetConsoleCP(1251);
    int choice;

    cout << "Какое действие хотите использовать?(1, 2, 3, 4): ";
    cin >> choice;
    handleChoice(choice);

    return 0;
}
