#include <locale>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    const int maxSize = 10000;
    int k;
    cout << "Введите размер массива: ";
    cin >> k;

    int* a = new int[k];
    srand((unsigned)time(NULL));

    cout << "Массив до преобразования: " << endl;
    for (int i = 0; i < k; i++) {
        a[i] = rand() % 201 - 100;
        cout << a[i] << " ";
    }
    cout << endl;

    int left = 0, right = k - 1; // Перенос чисел справа налево

    while (left < right) {
        if (a[left] < 0) {
            left++;
        }
        else if (a[right] >= 0) {
            right--;
        }
        else {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    cout << "Массив после преобразования: " << endl;
    for (int i = 0; i < k; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
