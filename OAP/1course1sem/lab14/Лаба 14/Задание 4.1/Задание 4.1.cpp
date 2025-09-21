#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	const int n = 2, m = 2;
	int h = 0;
	int A[n][m];
	using namespace std;
	cout << "Введите элементы массива" << endl;
	for (int i = 0; i < n; i++)
		for ( int j = 0; j < m; j++)
			cin >> A[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			h += A[i][j];
		}
	}
	if (h % 2 == 0)
		std::cout << "Чётная =" << h;
	else
		std::cout << "Нечётная =" << h;
}
