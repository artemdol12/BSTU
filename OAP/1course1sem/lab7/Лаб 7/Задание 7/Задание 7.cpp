#include <iostream>

int Pereborchisel(int n) {
    int count = 0;
    for (int i = 100; i <= 999; ++i) {
        int sum = (i / 100) + ((i / 10) % 10) + (i % 10);
        if (sum == n) {
            count++;
        }
    }

    return count;
}

int main() {
    using namespace std;
    setlocale(LC_CTYPE, "Russian");
    int n;
    cout << "Введите значение n (сумма цифр): ";
    cin >> n;

    if (n < 1 || n > 27) {
        cout << "Сумма цифр должна быть в диапазоне от 1 до 27." << endl;
        return 1;
    }

    int result = Pereborchisel(n);
    cout << "Количество трехзначных чисел, сумма цифр которых равна " << n << " = " << result << endl;

    return 0;
}
