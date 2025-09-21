#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
int main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	double  s1, s2, r1,r2, p, q, d1;
	cout << "Введите r1 = ";
	cin >> r1;
	cout << "Введите p = ";
	cin >> p;
	cout << "Введите q = ";
	cin >> q;
	s1 = M_PI * r1 * r1;
	if (p > q) {
		d1 = q / 2;
		r2 = d1;
		s2 = M_PI * r2 * r2;
	}
	else if (q > p)
		d1 = p / 2;
		r2 = d1+0;
		s2 = M_PI * r2 * r2;
	if (s1>s2)
		cout << "Не входит " << endl;
	else
		cout << "Входит " << endl;
	return 0;
}