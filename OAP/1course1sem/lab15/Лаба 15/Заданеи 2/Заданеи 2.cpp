#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	char* pStr; // указатель для адреса массива
	char c, * pc;
	int j, length, count = 0;
	cout << "Введите размер строки ";
	cin >> length;
	pStr = new char[length + 1]; // Выделение динам. пямяти
	cout << "Введите строку ";
	cin >> pStr;
	cout << "Введите символ ";
	cin >> c;
	pc = &c;
	for (j = 0; j < length; j++)
		if (pStr[j] == *pc)
			count++;
	cout << count << " повторяемый символ " << c << endl;
	delete[] pStr; // освобожд. динам. памяти
}