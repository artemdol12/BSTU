#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
int main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	double  s1, s2, s3, a, b, p, q, s, r, z;
	cout << "Введите a = ";
	cin >> a;
	cout << "Введите b = ";
	cin >> b;
	cout << "Введите q = ";
	cin >> q;
	cout << "Введите p = ";
	cin >> p;
	cout << "Введите s = ";
	cin >> s;
	cout << "Введите r = ";
	cin >> r;
	s1 = a * b;
	s2 = p * q;
	s3 = s * r;
	z = s2 + s3;
	if (s1>z) {
		cout << "Возможно разместить" << endl;
	}
	else
		cout << "Не возможно разместить " << endl;
	return 0;
}