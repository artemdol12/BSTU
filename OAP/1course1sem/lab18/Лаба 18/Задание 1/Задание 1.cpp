#include <iostream>
#include <initializer_list>
#include <limits>

using namespace std;
int fmax(const string& type, initializer_list<int> values) {
    int min_value = numeric_limits<int>::max();  
    for (int value : values) {
        if (value < min_value) {
            min_value = value;
        }
    }
    return min_value;
}

double fmax(const string& type, initializer_list<double> values) {
    double min_value = numeric_limits<double>::max();
    for (double value : values) {
        if (value < min_value) {
            min_value = value;
        }
    }
    return min_value;
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    cout << "Минимальное значение среди int: " << fmax("int", { 5, 2, 9, 3, 1 }) << endl;
    cout << "Минимальное значение среди double: " << fmax("double", { 3.14, 1.59, 2.65, 4.89, 0.99 }) << endl;
    cout << "Минимальное значение среди int и double: " << fmax("int", { 7, 8, 2, 1, 5 }) << endl;
    cout << "Минимальное значение среди int и double: " << fmax("double", { 3.7, 2.8, 1.9, 0.5 }) << endl;

    return 0;
}
