#include <ctime>
#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int n,s,max = 0, mult = 1, sum = 0, ** A, i = 0;
	cout << "Enter size ";
	cin >> n;
	srand(time(0));
	A = new int* [n];    //выделение динам.памяти
	for (int i = 0; i < n; i++)
		A[i] = new int[n];
	cout << "Array elements: ";
	for (int i = 0; i < n; i++) {
		*A[i] = (rand() % 201 - 100) + (rand() % 1000) / 1000.0;  // Случайное вещественное число от -100 до 100
	}
	for (int i = 0; i < n; i++)
		cout << *A[i] << " ";
	for (i = 0; i < n; i++) {
		if (max < *A[i]) {
			max = *A[i];
			s = i;
		}
	}
	printf("\n Максимальный элемент = ");
	printf("%d", max);
	for (int i = 0; i < s; i++)
	{
		if (*A[i] < 0)
			mult *= *A[i];
		else
			sum += *A[i];
	}
	cout << "\n Сумма положительных: " << sum << endl;
	cout << "Произведение отрицательных: " << mult << endl;
	for (int k = 0; k < n; k++) //освобождение памяти
		delete[] A[k];
	delete[] A;
}
