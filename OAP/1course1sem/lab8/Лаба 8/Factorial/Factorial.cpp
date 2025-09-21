#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int f = 1, b, a;
	cout << "Введите число:" << endl;
	cin >> a;
	for (b = 1;b <= a; b++)
	{
		f = f * b;
	}
	cout << "Ответ:" << f << endl;
	return 0;
}
