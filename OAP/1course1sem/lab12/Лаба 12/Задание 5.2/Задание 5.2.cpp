#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    setlocale(LC_CTYPE, "Russian");
    using namespace std;

    int m;
    srand(time(NULL));
    printf("Введите размер массива: ");
    cin >> (m);


    int* C = (int*)malloc(m * sizeof(int));
    int* D = (int*)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        *(C + i) = rand() % 99;
        *(D+ i) = rand() % 99;
    }

    // Вывод массива
    printf("Массив C: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", *(C + i));
    }
    printf("\n");
    printf("Массив D: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", *(D + i));
    }
    printf("\n");
    int count = 0;
    for (int i = 0; i < m; i++) {
        if (C[i] == D[i]) {
            count++;
        }
    }
    cout << "Количество элементов, где C[k] = D[k]: " << count << endl;
    count = 0;
    for (int i = 0; i < m; i++) {
        if (C[i] > D[i]) {
            count++;
        }
    }
    cout << "Количество элементов, где C[k] > D[k]: " << count << endl;
    count = 0;
    for (int i = 0; i < m; i++) {
        if (C[i] < D[i]) {
            count++;
        }
    }
    cout << "Количество элементов, где C[k] < D[k]: " << count << endl;
    return 0;
}
