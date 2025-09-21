#include <iostream>
using namespace std;

int massiv(int* M, int); //прототип
void matrix();            //прототип

int main(void)
{
	setlocale(LC_CTYPE, "Russian");
	int choice;
	do
	{
		cout << "Выберите вариант работы" << endl;
		cout << "1 - с одномерным массивом" << endl;
		cout << "2 - с матрицей" << endl;
		cout << "3 - выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:  int* M, size, i, av;
			cout << "Введите размер массива ";
			cin >> size;
			M = new int[size];
			for (i = 0; i < size; i++)
			{
				cout << "Введите " << i + 1 << " число ";
				cin >> *(M + i);
			}
			av = massiv(M, size);
			cout << "Результат=" << av << endl;
			delete[] M;
			break;
		case 2:  matrix();
			break;
		case 3:  break;
		}
	}
	while (choice != 3);
}
int massiv(int* M, int size)
{
	int sum = 0, avar;
	for (int i = 0; i < size; i++)
		sum += *(M + i);
	avar = sum / size;
	return avar;
}
void matrix()
{
	int** A, row, col, i, j, m;
	cout << "Введите число строк матрицы ";
	cin >> row;
	cout << "Введите чиcло столбцов ";
	cin >> col;
	A = new int* [row];
	for (i = 0; i < row; i++)
		A[i] = new int[col];
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
		{
			cout << "Введите A[" << i << "],[" << j << "]= ";
			cin >> *(*(A + i) + j);
		}
	m = A[0][0];
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			if (*(*(A + i) + j) > m)
				m = *(*(A + i) + j);
	cout << "Результат=" << m << endl;
	for (i = 0; i < row; i++)
		delete A[i];
	delete[] A;
}
