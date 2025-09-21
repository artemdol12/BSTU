#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    const int n = 3, m = 3;
    int A[n][m];
    int k, f = 0;
    cout << "Введите 9 элементов массива (матрица 3x3):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> *(*(A + i) + j);
        }
    }
    cout << "Введите строку (начиная с 0, заканчивая 2) k = ";
    cin >> k;
    cout << "Введенная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << *(*(A + i) + j) << " ";
        }
        cout << endl;
    }
    for (int j = 1; j < m; j++) {
        if (*(*(A + k) + j) >= *(*(A + k) + j - 1)) {
            f = 1;
            break;
        }
    }
    cout << "f = " << f << endl;
    return 0;
}
