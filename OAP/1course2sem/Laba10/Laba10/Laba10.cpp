#include <iostream>
#include <cmath>

using namespace std;

double calculate(int k, int n) {
    if (k == n) {
        return sqrt(1 + 2 * n);
    }
    return sqrt(1 + (n + k) * calculate(k + 1, n));
}

int main() {
    setlocale(LC_ALL, "Rus");
    int n;
    cout << "Введите n: ";
    cin >> n;
    double result = calculate(1, n); 
    cout << "Результат: " << result << endl;
    return 0;
}