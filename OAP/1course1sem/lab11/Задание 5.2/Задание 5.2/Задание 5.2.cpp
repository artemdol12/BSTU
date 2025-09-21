#include <iostream>  
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int A, maskA, maskB = 0, n, p, B,q; char tmp[33];
	cout << "Ввести степень двойки, чтобы инвертировать кол-во битов сколько надо";
	cin >> n;
	cout << "Ввести от какого бита начинать инвертировать";
	cin >> p;
	maskA = pow(2, n) - pow(2, p);
	cout << " Введите A: " << endl;
	cin >> A;
	cout << "Второе число В="; cin >> B;
	_itoa_s(A, tmp, 2);
	cout << " Число А: " << tmp << endl;
	_itoa_s(B, tmp, 2);
	cout << " Число B: " << tmp << endl;
	_itoa_s(maskA, tmp, 2);
	cout << " Маска для А: " << tmp << endl;
	_itoa_s(A ^ maskA, tmp, 2);
	cout << " Результат: " << tmp << endl << endl;
	cout << "Введите с какой позиции начинать замену";
	cin >> q;
	maskA = ~maskB >> 1;
	cout << "Маска для B: " << tmp << endl;
	_itoa_s((B & maskB) >> 1, tmp, 2);

	cout << " Результат: " << tmp << endl << endl;
}
