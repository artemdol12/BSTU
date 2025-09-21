#include <iostream>
#include <iomanip>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	int a, b, c;
	cout << "Введите два значения ";
	cin >> a >> b;
	cout << "Оригинальные значения: a = " << a << ", b = " << b << endl;
	c = a + b;
	b = c - b;
	a = c - a;
	cout << "Замененное значение a = " << a << ", b = " << b << endl;
}