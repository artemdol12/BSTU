#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int count = 6, n = 1;
	float b, m = 9999;
	for (int i = 1; i < count; i++)
	{
		cout << "Введите b" << i << endl;
		cin >> b;
		if (b < m)
		{
			m = b;
			n = i;
		}
	}
	cout << "b" << n << " = " << m << endl;
}