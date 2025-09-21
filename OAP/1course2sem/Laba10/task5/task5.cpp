#include <iostream>

using namespace std;

int binomialCoefficient(int n, int m) {
    if (m == 0 || m == n) {
        return 1;
    }
    return binomialCoefficient(n - 1, m) + binomialCoefficient(n - 1, m - 1);
}

int main() {
    setlocale(LC_ALL, "rus");
    int n, m;
    cout << "Введите n и m (0 <= m <= n): ";
    cin >> n >> m;

    if (m < 0 || m > n) {
        cout << "Ошибка: m должно удовлетворять условию 0 <= m <= n." << endl;
        return 1;
    }

    int result = binomialCoefficient(n, m);
    cout << "C(" << n << ", " << m << ") = " << result << endl;
    return 0;
}