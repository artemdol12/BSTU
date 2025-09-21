#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	float c;
	double r, u, s;
	printf("Введите c: ");
	scanf("%f", &c);
	r = c / 2 * M_PI;
	s = M_PI * r * r;
	printf("r = % f\n", r);
	printf("s = % f\n", s);
}
