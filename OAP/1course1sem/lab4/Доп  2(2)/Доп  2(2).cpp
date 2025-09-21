#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	float m;
	double r, u, s, n;
	printf("Введите m: ");
	scanf("%f", &m);
	r = (m + 5) / 2;
	s = (m - 5) / 2;
	n = r - s;
	printf("(Первая часть) r = % f\n", r);
	printf("(Вторая часть) s = % f\n", s);
	printf("n = % f\n", n);
}
