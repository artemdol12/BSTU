#include <iostream>
#include <cmath>
int main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	double  d, a, b, c;
	cout << "Введите a = ";
	cin >> a;
	cout << "Введите b = ";
	cin >> b;
	cout << "Введите c = ";
	cin >> c;
	if (a == 0) {
		d = ((a + b + c) / 3);
	}
	else if (b == 0)
		d = ((a + b + c) / 3);
	else if (c == 0)
		d = ((a + b + c) / 3);
	else
		d = cbrt(a * b * c);
	    cout << "d = " << d << endl;
	return 0;
}