#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    setlocale(LC_CTYPE, "Russian");
    using namespace std;

    int n;
    srand(time(NULL));
    printf("Введите размер массива: ");
    cin >> (n);
    // Выделение памяти для массива
    int* A = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        A[i] = rand() % 99;
    }

    // Вывод массива
    printf("Массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    printf("Максимум: %d\n", max);
    return 0;
}
