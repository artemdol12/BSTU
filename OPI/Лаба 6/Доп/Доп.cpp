#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);
	int choice;
	int k;
	puts("Проверяем работу светофора(1- да, 2-нет)");
	cin >> k;
	switch (k)
	{
		case 1: { puts("Проверяем значение светофора(1-зеленый, 2- красный)");
			cin >> k;
			switch(k){
				case 1: {
					cout << "Переходим дорогу";
			break;
	}
				case 2: {
					cout << "Ждём смены сигнала светофора и переходим дорогу";
					break;
				}
	}
		
		break;
	}
	case 2: {
		cout << "Проверяем дорогу и переходим";
		break;
	}
	default: {
		puts("Некорректный вариант"); break;
	}
		   return 0;
	}
}