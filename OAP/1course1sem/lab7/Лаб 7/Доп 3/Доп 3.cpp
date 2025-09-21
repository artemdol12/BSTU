#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	float C1, C2, a, b;
	int n = 0;
	printf("Введите кол-во литров воды в первом сосуде: ");
	scanf_s("%f", &C1);
	printf("Введите кол-во литров воды во втором сосуде: ");
	scanf_s("%f", &C2);
	printf("Кол-во литров воды в первом сосуде\t\t Кол-во литров воды во втором сосуде\n");
	printf("%f\t\t\t\t\t %f\n", C1, C2);
	while (n <= 12)
	{
		a = C1 / 2;
		C1 = C1 - a;
		C2 = C2 + a;
		n = n + 1;
		printf("%f\t\t\t\t\t %f\n", C1, C2);
		b = C2 / 2;
		C2 = C2 - b;
		C1 = C1 + b;
		n = n + 1;
		printf("%f\t\t\t\t\t %f\n", C1, C2);
	}
}
