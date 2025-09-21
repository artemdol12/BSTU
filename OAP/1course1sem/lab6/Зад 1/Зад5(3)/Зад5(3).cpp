#include <iostream>
#include <stdio.h>
#include <cmath>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	float z, q, y, x, a, j, sd;
	y = -1.55;
	a = 1;
	for (int n = 0; n < 3; n++)
	{
		printf("Введите j ");
		scanf_s("%f", &j);
		while (a < 2)
		{
			z = sqrt(a + 1) - tan(j + y);
			q = exp(-j * 0.1 * y) + pow(3 * z, 2);
			printf("j = %5.2f\t", j);
			printf("q = %5.2f\n", q);
			a = a + 0.2;
		}
		a = 1;
	}
}
