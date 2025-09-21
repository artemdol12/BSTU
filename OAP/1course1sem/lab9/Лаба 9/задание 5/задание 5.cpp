#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	float n = 200, a = 5, b = 11;
	double h = (b - a) / n;
	double x = a;
	double s = 0;
	while (x < (b - h)) {
		s += h * (exp(x) + 6 + exp(x + h) + 6) / 2;
		x = x + h;
	}
	cout << "Метод трапеции: " << s;
}
