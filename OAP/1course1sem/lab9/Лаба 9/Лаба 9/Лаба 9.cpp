#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	float n = 200, a = 5, b = 11, s1 = 0, s2 = 0, i = 1, x, h, z;
	h = (b - a) / (2 * n);
	x = a + 2 * h;
	while (i < n)
	{
		s1 = s1 + (exp(x) + 6);
		x = x + h;
		s2 = s2 + (exp(x) + 6);
		x = x + h;
		i = i + 1;
	}
	z = h / 3 * (exp(a) + 6 + 4 * (exp(a + h) + 6) + 4 * s1 + 2 * s2 + exp(b) + 6);//вычисление значения площади криволинейной трапеции
	cout << "Метод параболы: " << z;
}
