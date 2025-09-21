#include <ctime>
#include <iostream>
using namespace std;
void main()
{
	int size, mult = 1, sum = 0, ** A, i = 0;
	cout << "Enter size ";
	cin >> size;
	srand(time(0));
	A = new int* [size];    //выделение динам.памяти
	for (int i = 0; i < size; i++)
		A[i] = new int[size];
	for (int j = 0; j < size; j++)
		A[i][j] = 1 + rand() % 10;
	for (int** ptr = A; ptr != A + size; ++ptr)
	{
		for (int* it = *ptr; it != *ptr + size; ++it)
		{
			cout << "\t" << *it;
			if (*it % 2 == 0)
			{
				mult *= *it;
				sum += *it;
			}
		}
		cout << endl;
	}
	cout << "sum: " << sum << endl;
	cout << "mult: " << mult << endl;
	for (int k = 0; k < size; k++) //освобождение памяти
		delete[] A[k];
	delete[] A;
}
