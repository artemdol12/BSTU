#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	float x, y, z;
	double t, u;
	printf("Введите x: ");
	scanf("%f", &x);
	printf("Введите y: ");
	scanf("%f", &y);
	printf("Введите z: ");
	scanf("%f", &z);
	t = (abs(x) + abs(y) + abs(z)) / 3;
	u = cbrt(abs(x) * abs(y) * abs(z));
	printf("t=%f\n", t);
	printf("u=%f\n", u);
}
