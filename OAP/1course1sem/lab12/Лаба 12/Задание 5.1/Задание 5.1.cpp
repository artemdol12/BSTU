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


    int* A = (int*)malloc(n * sizeof(int));
    int* B = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        *(A + i) = rand() % 99;
        *(B + i) = rand() % 99;
    }

    // Вывод массива
    printf("Массив A: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(A + i));
    }
    printf("\n");
    printf("Массив B: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(B + i));
    }
    printf("\n");
    int t;
    printf("Введите число, которое дожно быть больше других чисел (t)\n");
    cin >> (t);
    int* ptr1 = B;
    int* ptr2 = A;
    printf("Массив изменнёный A: ");
    for (int i = 0; i < n; i++) {
        if (*ptr2 > t) {
        }
        else
        printf("%d ", *ptr2);
        ptr2++;
    }
    printf("\n");
    printf("Массив изменнёный B: ");
    for (int i = 0; i < n; i++) {
        if (*ptr1 > t) {
        }
        else
            printf("%d ", *ptr1);
        ptr1++;
    }
    printf("\n");
    if (A > B)
        cout << "В массиве A больше чисел \n";
    else
        cout << "В массиве В больше чисел";
    return 0;
}
