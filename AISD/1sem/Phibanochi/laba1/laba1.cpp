#include <iostream>
#include <chrono> 

using namespace std;
using namespace std::chrono;

int n;

int Rekursiya(int number) {
    if (number == 0)
        return 0;
    if (number == 1)
        return 1;
    return Rekursiya(number - 1) + Rekursiya(number - 2);
}


void rek() {
    auto start = high_resolution_clock::now(); 
    int result = Rekursiya(n);
    auto end = high_resolution_clock::now(); 

    cout << "Число Фибоначчи через рекурсию: " << result << endl;

    auto duration = duration_cast<microseconds>(end - start);

    auto minutes_s = duration_cast<minutes>(duration);
    duration -= minutes_s;
    auto seconds_s = duration_cast<seconds>(duration);
    duration -= seconds_s;
    auto milliseconds_s = duration_cast<milliseconds>(duration);
    duration -= milliseconds_s;
    auto microseconds_s = duration_cast<microseconds>(duration);
    duration -= microseconds_s;
    auto nanoseconds_s = duration_cast<nanoseconds>(duration);

    printf("\nВремя выполнения рекурсии: %lld минут %lld секунд %lld миллисекунд %lld микросекунд %lld наносекунд\n",
           minutes_s.count(), seconds_s.count(), milliseconds_s.count(), microseconds_s.count(), nanoseconds_s.count());
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    long long int a = 0, b = 1, c, i;

    cout << "Введите число n для вычисления n-го числа Фибоначчи: \n";
    cin >> n;
    n = n - 1;
    cout << "Циклический способ:\n";
    auto start_cycle = high_resolution_clock::now(); 
    for (i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    cout << " " << a;
    auto end_cycle = high_resolution_clock::now(); 

    auto duration_cycle = duration_cast<microseconds>(end_cycle - start_cycle);

    auto minutes_cycle = duration_cast<minutes>(duration_cycle);
    duration_cycle -= minutes_cycle;
    auto seconds_cycle = duration_cast<seconds>(duration_cycle);
    duration_cycle -= seconds_cycle;
    auto milliseconds_cycle = duration_cast<milliseconds>(duration_cycle);
    duration_cycle -= milliseconds_cycle;
    auto microseconds_cycle = duration_cast<microseconds>(duration_cycle);
    duration_cycle -= microseconds_cycle;
    auto nanoseconds_cycle = duration_cast<nanoseconds>(duration_cycle);

    printf("\nВремя выполнения цикла: %lld минут %lld секунд %lld миллисекунд %lld микросекунд %lld наносекунд\n",
           minutes_cycle.count(), seconds_cycle.count(), milliseconds_cycle.count(), microseconds_cycle.count(), nanoseconds_cycle.count());

    rek();
    return 0;
}