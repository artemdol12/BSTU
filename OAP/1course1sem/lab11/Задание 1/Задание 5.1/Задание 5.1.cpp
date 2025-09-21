#include <iostream>  
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int A, maskA = 16382; char tmp[33];
	cout << " Введите A: " << endl;
	cin >> A;
	_itoa_s(A, tmp, 2);
	cout << " Число А: " << tmp << endl;
	_itoa_s(maskA, tmp, 2);
	cout << " Маска для А: " << tmp << endl;
	_itoa_s(A ^ maskA, tmp, 2);
	cout << " Результат: " << tmp << endl << endl;
}