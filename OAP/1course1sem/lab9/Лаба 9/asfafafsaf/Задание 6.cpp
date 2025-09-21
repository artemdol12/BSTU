#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x * x * x + 2 * x - 1;
}

int main() {
    setlocale(LC_ALL, "RU");
    double x_vals[] = { 0.0, 1.0, 2.0, 3.0, 4.0 };
    double f_vals[] = { f(0.0), f(1.0), f(2.0), f(3.0), f(4.0) };
    double e = 0.0001;
    int n = sizeof(x_vals) / sizeof(x_vals[0]);
    double a, b;
    // Ищем отрезок, на котором функция меняет знак
    for (int i = 0; i < n - 1; i++) {
        if (f_vals[i] * f_vals[i + 1] < 0) {
            a = x_vals[i];
            b = x_vals[i + 1];
            cout << "Отрезок с корнем: [" << a << ", " << b << "]" << endl;
            break;
        }
    }
    // Метод дихотомии для нахождения корня
    double x;
    while (abs(b - a) > 2 * e) {
        x = (a + b) / 2;
        if (f(a) * f(x) <= 0) {
            b = x;
        }
        else {
            a = x;
        }
    }
    x = (a + b) / 2;
    cout << "Метод дихотомии: " << x << endl;
    return 0;
}
