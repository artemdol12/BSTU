#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	int choice;
	unsigned char xB = ' ', xS = ' ';
	unsigned char yB = ' ', yS = ' ';
	unsigned char z = ' ';
	cout << "Âûáåðèòå çàäàíèå (1,2,3, 4 äëÿ âûõîäà): ";
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "Ââåäèòå âòîðóþ áóêâó ôàìèëèè íà àíãëèéñêîì ïðîïèñíîé:";
		cin >> xB;
		cout << "Ââåäèòå âòîðóþ áóêâó ôàìèëèè íà àíãëèéñêîì ñòðî÷íîé:";
		cin >> xS;
		if (int(xS) < 127 && int(xB) < 127) {
			cout << "Ðàçíèöà çíà÷åíèé êîäîâ:" << (int)xB - (int)xS;
		}
		else {
			cout << "Ââåäåííû íåêêîððåêòíûå ñèìâîëû!";
		}
		break;
	case 2:
		cout << "Ââåäèòå âòîðóþ áóêâó èìåíè íà ðóññêîì ïðîïèñíîé:";
		cin >> yB;
		cout << "Ââåäèòå âòîðóþ áóêâó èìåíè íà ðóññêîì ñòðî÷íîé:";
		cin >> yS;

		if (192 <= int(yB) && 192 <= int(yS)) {
			cout << "Ðàçíèöà çíà÷åíèé êîäîâ:" << (int)yB - (int)yS;
		}
		else {
			cout << "Ââåäåíû íåêîððåêòíûå ñèìâîëû!";
		}
		break;
	case 3:
		cout << "Ââåäèòå êîëè÷åñòâî öèôð èìåíè:";
		cin >> z;
		if (48 <= int(z) && int(z) <= 57) {
			cout << "Êîä ñèìâîëà:" << (int)z;
		}
		else {
			cout << "Ââåäåí íåêîððåêòíûé ñèìâîë!";
		}
		break;
	case 4:
		break;
	default:
		cout << "Ââåäåííî íåêîððåêòíîå ÷èñëî!";
		break;
	}
}