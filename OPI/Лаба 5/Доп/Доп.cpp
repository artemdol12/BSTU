#include <iostream>
void main()
{
	setlocale(LC_ALL, "Russian");
	using namespace std;
	const int max_size = 99;
	int n, unique = 0, par = 0;
	float z[max_size];
	cout << "Введите размер массива z: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		*(z + i) = rand() % 23;
		cout << *(z + i) << "\t" << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (*(z + i) == *(z + j))
			{
				unique = 1;
				break;
			}
		}
		if (unique == 0)
			par++;
		unique = 0;
	}
	cout << "Кол-во различных чисел: " << par << endl;
}
