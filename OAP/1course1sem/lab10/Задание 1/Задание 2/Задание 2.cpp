#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int i, k, size = 4;
	double sum = 0, sum1 = 0;
	float massivA[] = { 5, -4, 17.1, 9, 1 };
	cout << "Введите номер элемента (от 0 до 4): ";
	cin >> k;
	for (i = k; i <= size; i++)
		massivA[i] = massivA[i + 1];
	size--;
	for (i = 0; i <= size; i++) {
		cout << massivA[i] << endl;
		sum += massivA[i];
	}
	sum1 = sum / 4;
	cout << "Средняя сумма массива = " << sum1 << endl;
}