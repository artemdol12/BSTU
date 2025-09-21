#include <iostream>
#include <cmath>
int main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	double x1, x2, d, a, b, c;
	cout << "Введите a = ";
	cin >> a;
	cout << "Введите b = ";
	cin >> b;
	cout << "Введите c = ";
	cin >> c;
	d = b * b - 4 * a * c;
	if (d > 0) {
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);
		cout << "x1=" << x1 << "  x2=" << x2 << endl;
	}
	else
		cout << "Корней нет"<< endl;
	return 0;
}