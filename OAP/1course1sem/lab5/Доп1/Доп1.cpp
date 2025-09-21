#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	int a, b, c, sum = 0;
	cout << "Введите a =" << endl;
	cin >> a;
	cout << "Введите b =" << endl;
	cin >> b;
	cout << "Введите c =" << endl;
	cin >> c;
	a % 5 == 0 ? sum += a : sum += 0;
	b % 5 == 0 ? sum += b : sum += 0;
	c % 5 == 0 ? sum += c : sum += 0;
	sum == 0 ? cout << "Error" : cout << "Sum=" << sum;
}