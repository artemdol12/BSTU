#include <iostream>
#include <cmath>
#include <vector>

int main()
{
    using namespace std;
    setlocale(LC_ALL, "rus");

    int N, K;
    cout << "Введите границу чисел: ";
    cin >> N;
    K = N;
    if (N < 1) {
        cout << "Граница должна быть положительным числом." << endl;
        return 0;
    }

    int L = 1, X = 0, n;
    while (L <= N) {
        if (X % 2) {
            X = L + (N - L + 1) / 2;
            cout << "Это ваше число? " << X << " (1-больше, 2-меньше, 3-угадал): ";
        }
        else {
            X = L + (N - L) / 2;
            cout << "Это ваше число? " << X << " (1-больше, 2-меньше, 3-угадал): ";
        }
        cin >> n;

        if (n < 1 || n > 3) {
            cout << "Неверный ввод. Пожалуйста, введите 1, 2 или 3." << endl;
            continue;
        }

        switch (n) {
        case 1: L = X + 1; break;
        case 2: N = X - 1; break;
        case 3:
            cout << "Ура!!! Спасибо за участие в игре. Удачи!" << endl;
            int max_steps = static_cast<int>(log2(K)) + 1;
            cout << "Максимальное количество шагов = " << max_steps << endl;

            vector<int> steps;
            int current = K;

            while (current >= 1) {
                steps.push_back(current);
                if (current == 1) {
                    break;
                }
                current = (current + 1) / 2;
            }

            for (int step : steps) {
                cout << step << endl;
            }
            return 0;
        }

        if (L > N) {
            cout << "Вы попытались обмануть программу, просьба больше такого не делать :(" << endl;
            return 0;
        }
    }  
}