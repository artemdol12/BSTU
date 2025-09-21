#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;
void main()
{
	double a = 105e-4, m =4, i = 7, z = 3.8, x, s, p;
	for (int n = 0;  n < 3; n++)
	{
		setlocale(LC_CTYPE, "Russian");
		cout << "\n Введите x = ";
			cin >> x;
		s = exp(-a * x) - log(i / x * m) / log(m)*log(m);
		if (s > 2 * x)
			p = (-i * s) * (-i * s);
		else if (s <= 2 * x)
			p = sin(-6 * x);
		cout << "\n p = " << p ;
	}
}
