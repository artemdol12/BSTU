#include <ctime>
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int n, m, mult = 1, sum = 0, ** A, max = 0, min = 999, summin = 0, summax = 0;

    // Ввод размеров матрицы
    cout << "Строки (n): ";
    cin >> n;
    cout << "Колонки (m): ";
    cin >> m;

    srand(time(0));

    // Выделение памяти для матрицы размером n x m
    A = new int* [n];
    for (int i = 0; i < n; i++)
        A[i] = new int[m];

    // Заполнение матрицы случайными числами от 1 до 10
    cout << "Элементы матрицы:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = 1 + rand() % 10;  // Генерация случайного числа от 1 до 10
            cout << "\t" << A[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            min = 999;
            for (int j = 0; j < m; j++) {
                if (min > A[i][j]) {
                    min = A[i][j];
                }
            }
            summin += min;
        }
        else {
            max = 0;
            for (int j = 0; j < m; j++) {
                if (max < A[i][j]) {
                    max = A[i][j];
                }
            }
            summax += max;
        }
        cout << endl;
    }
    sum = summax + summin;
    cout << "Сумма наименьших элементов ее нечетных строк и наибольших элементов ее четных строк = " << sum;
    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;

    return 0;
}
