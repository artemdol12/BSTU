#include <iostream>
void main()
{
	char t[3][20];
	int i, n;
	using namespace std;
	cout << "Input size (<=3): ";
	cin >> n;
	cin.ignore(cin.rdbuf()->in_avail());//Очищает буфер
	for (i = 0; i < n; i++)
	{
		cout << "Input string: ";
		gets_s(t[i]);
	}
	for (i = 0; i < n; i++)
		puts(t[i]);
}
