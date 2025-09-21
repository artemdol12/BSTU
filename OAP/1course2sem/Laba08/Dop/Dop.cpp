#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    deque<double> dq;
    string input;

    cout << "Введите вещественные числа через пробел: ";
    getline(cin, input);

    stringstream ss(input);
    double num;
    while (ss >> num) {
        dq.push_back(num);
    }

    if (dq.empty()) {
        cout << "Очередь пуста" << endl;
    }
    else {
        double max_val = *max_element(dq.begin(), dq.end());

        while (dq.front() != max_val) {
            dq.push_back(dq.front());
            dq.pop_front();
        }

        cout << "Результат: ";
        for (auto n : dq) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}