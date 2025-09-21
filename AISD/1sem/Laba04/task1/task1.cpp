#include <iostream>
#include <algorithm>

int main() {
    using namespace std;

    setlocale(LC_ALL, "rus");

    int N;
    cout << "Введите количество товаров: ";
    cin >> N;

    if (N < 1 || N > 10000) {
        cout << "Количество чисел должно быть положительным и не превышать 10000." << endl;
        return 0;
    }

    srand(static_cast<unsigned int>(time(0)));

    int* A = new int[N];
    for (int i = 0; i < N; ++i) {
        A[i] = rand() % 100 + 1;
    }

    cout << "Цены в массиве A: ";
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    sort(A, A + N, greater<int>());
    int maxSum = 0;
    int* order = new int[N];
    int left = 0, right = N - 1;
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            order[i] = A[left];
            left++;
            maxSum += order[i];
        }
        else {
            order[i] = A[right];
            right--;
        }
    }

    cout << "Порядок пробивания: ";
    for (int i = 0; i < N; ++i) {
        cout << order[i] << " ";
    }
    cout << endl;

    cout << "Максимальная сумма чека: " << maxSum << endl;

    delete[] A;
    delete[] order;

    return 0;
}