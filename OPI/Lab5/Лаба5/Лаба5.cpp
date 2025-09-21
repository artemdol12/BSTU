#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);
	int choice;
	unsigned char xB = ' ', xS = ' ';
	unsigned char yB = ' ', yS = ' ';
	unsigned char z = ' ';
	int k;
	puts("Какое действие хотите использовать?(1, 2, 3, 4)");
	cin >> k;
	switch (k)
	{
	case 1: {
		cout << "Введите вторую букву фамилии на английском прописной:";
		cin >> xB;
		cout << "Введите вторую букву фамилии на английском строчной:";
		cin >> xS;
		if ( int(xS) - int(xB) == 32) {
			cout << "Разница значений кодов:" << (int)xB - (int)xS;
		}
		else
			cout << "Ошибка(Ведите, что просится)";
		break;
	}
	case 2: {
		cout << "Введите вторую букву имени на русском языке прописной:";
		cin >> yB;
		cout << "Введите вторую букву имени на русском языке строчной:";
		cin >> yS;
		if (int(yB) - int(yS) == -32) {
			cout << "Разница значений кодов:" << (int)yB - (int)yS;
		}
		else
			cout << "Ошибка(Ведите, что просится)";
		break;
	}
	case 3: {
		cout << "Ввести число (кол-во букв в фамилии):";
		cin >> z;
			cout << "Код числа:" << (int)z;
		break;
	}
	case 4: {
		cout << "Выход из программы." << endl;
		return 0;
	}
	default: {
		puts("Некорректный вариант"); break;
	}
		   return 0;
	}
}