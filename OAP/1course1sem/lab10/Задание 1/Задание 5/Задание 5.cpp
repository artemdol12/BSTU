#include <locale>
#include <iostream>

void main()
{
	setlocale(LC_ALL, "rus");
	using namespace std;
	const int maxSize = 30;
	int n, i, kmin = 0;
	int a[maxSize];
	double BIGNUM = 10000;
	cout << "Введите размер массива " << endl;
	cin >> n;
	if (n > BIGNUM)
		return;
	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
		if (a[i] % 7 == 0)
		;
		else
		cout << a[i] << " ";
	}
	cout << endl;
}