#include <iostream>
#include <algorithm>

int main() {
    using namespace std;

    setlocale(LC_ALL, "rus");

    int N, max = 0, k = 0;
    cout << "Введите количество участников: ";
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

    cout << "Баллы участников: ";
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
    cout << "Призеры это участники набравшие баллы: ";
    for (int i = 0; i < 3; ++i) {
        max = 0;
        for (int i = 0; i < N; ++i) {
            if (max < A[i]) {
                max = A[i];
                k = i;
            }

        }
        A[k] = 0;
            for (int i = 0; i < N; i++) {
                if (max == A[i]) {
                    cout << " " << max;
                    A[i] = 0;
                }
            }
        cout << " " << max;
    }
    
    delete[] A;
    return 0;
}