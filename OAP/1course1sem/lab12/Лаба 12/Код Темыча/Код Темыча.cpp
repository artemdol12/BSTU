#include <iostream> 
void main()
{
	setlocale(LC_ALL, "Russian");
	using namespace std;
	const int max_size = 99;
	int k, n, a;
	float X[max_size], Y[max_size], Z[max_size];
	cout << "Введите размер массива X: "; cin >> k;
	cout << "Введите размер массива Y: "; cin >> n;
	for (int i = 0; i < k; i++)
	{
		*(X + i) = rand() % 20;
		cout << *(X + i) << "\t" << (X + i) << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		*(Y + i) = rand() % 20;
		cout << *(Y + i) << "\t" << (Y + i) << endl;
	}
	for (int i = 0; i < max(k, n); i++)
	{
			if (X[i] == Y[i]) {
				*(Z + i) = Y[i];
				a = i;
			}
	}
	for (int i = 0; i < a; i++)
	{
		cout << *(Z + i) << "\t" << endl;
	}
}