#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

int n;

int Rekursiya(int number) {
    if (number == 0)
        return 0;
    if (number == 1)
        return 1;
    return Rekursiya(number - 1) + Rekursiya(number - 2);
}

void rek() {
    clock_t start = clock();
    int* fibNumbers = new int[n];
    for (int count = 0; count < n; count++) {
        fibNumbers[count] = Rekursiya(count);
    }
    clock_t end = clock();
    cout << "Числа Фибоначчи (рекурсия):\n";
    for (int count = 0; count < n; count++) {
        cout << " " << fibNumbers[count];
    }

    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nВремя выполнения рекурсии (без вывода): %f секунд\n", seconds);

    delete[] fibNumbers;
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    int a, b, c, i;
    a = 0;
    b = 1;

    cout << "Введите количество чисел Фибоначчи для вывода: \n";
    cin >> n;

    cout << "Циклический способ:\n";
    clock_t start_cycle = clock();
    for (i = 0; i < n; i++) {
        cout << " " << a;
        c = a + b;
        a = b;
        b = c;
    }
    clock_t end_cycle = clock();
    double seconds_cycle = (double)(end_cycle - start_cycle) / CLOCKS_PER_SEC;
    printf("\nВремя выполнения цикла: %f секунд\n", seconds_cycle);

    rek();

    return 0;
}