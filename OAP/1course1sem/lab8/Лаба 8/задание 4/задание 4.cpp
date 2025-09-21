#include <iostream>
using namespace std;
void main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	int count = 6;
	float z, m = 0, x, x3 = 0, c, sum;
	for (int i = 1; i < count; i++)
	{
		cout << "Введите x" << i << endl;
		cin >> x;
		c = (x - 2) * (x - 2);
		sum = c;
		m += sum;
		if (i == 3)
		{
			x3 = x;
		}
	}
	z = 8 * x3 + m;
	cout << "z" << " = " << z << endl;
}