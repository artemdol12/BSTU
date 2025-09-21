#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	float y, a, n;
	double t, u, s;
	printf("¬ведите y: ");
	scanf("%f", &y);
	printf("¬ведите a: ");
	scanf("%f", &a);
	printf("¬ведите n: ");
	scanf("%f", &n);
	t = 1 / sqrt(y) + 14 * a;
	u = (t + 1) / (a + 2);
	s = log((2 * n / 3) + exp(-n) / u);
	printf("t=%f\n", t);
	printf("u=%f\n", u);
	printf("s=%f\n", s);
}
