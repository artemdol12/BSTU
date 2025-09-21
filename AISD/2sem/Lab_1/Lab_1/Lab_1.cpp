#include <iostream>
#include <locale>
#include <cmath>

using namespace std;

void hanoi3(int from, int to, int n) {
    if (n == 1) {
        cout << "Переместить диск 1 со стержня " << from << " на стержень " << to << ".\n";
    }
    else {
        int tmp = 6 - from - to;
        hanoi3(from, tmp, n - 1);
        cout << "Переместить диск " << n << " со стержня " << from << " на стержень " << to << ".\n";
        hanoi3(tmp, to, n - 1);
    }
}

void hanoiK(int from, int to, int n, int extra) {
    if (n == 0) return;

    if (n == 1) {
        cout << "Переместить диск 1 со стержня " << from << " на стержень " << to << ".\n";
        return;
    }

    hanoiK(from, extra, n - 1, to);
    cout << "Переместить диск " << n << " со стержня " << from << " на стержень " << to << ".\n";
    hanoiK(extra, to, n - 1, from);
}

int main() {
    setlocale(LC_ALL, "Russian");

    int N, K;
    cout << "Введите кол-во дисков: ";
    cin >> N;
    cout << "Введите кол-во стержней: ";
    cin >> K;

    if (N <= 0) {
        cout << "Ошибка: число дисков должно быть больше 0!\n";
        return 0;
    }

    if (N > 1) {
        if (K < 3) {
            cout << "Ошибка: должно быть минимум 3 стержня!\n";
            return 0;
        }
    }

    if (N > 20) {
        cout << "Ошибка: слишком много дисков, система не сможет посчитать!\n";
        return 0;
    }

    cout << "\nРешение:\n";
    if (K == 3) {
        hanoi3(1, 3, N);
    }
    else {
        hanoiK(1, K, N, 2);
    }

    return 0;
}