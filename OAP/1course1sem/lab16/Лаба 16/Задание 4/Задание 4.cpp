#include <iostream>
using namespace std;

int sumBelowDiagonal(int** A, int n) {
    int totalSum = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            totalSum += A[i][j];
        }
    }
    return totalSum;
}

int sumDiagonali() {
    setlocale(LC_CTYPE, "Russian");
    int n;
    cout << "Введите размер матрицы n (n x n): ";
    cin >> n;

    // Создаем динамическую матрицу
    int** A = new int* [n];
    for (int i = 0; i < n; ++i) {
        A[i] = new int[n];
    }

    cout << "Элементы матрицы:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 1 + rand() % 10;  // Генерация случайного числа от 1 до 10
            cout << "\t" << A[i][j];
        }
        cout << endl;
    }
    int result = sumBelowDiagonal(A, n);
    cout << "Сумма элементов ниже главной диагонали: " << result << endl;
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
