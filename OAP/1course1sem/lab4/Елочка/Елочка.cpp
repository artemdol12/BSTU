#include <iomanip> 
#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	char c, probel; probel = ' ';
	cout << "Введите символ "; cin >> c;
	cout << setw(39) << setfill(probel) << probel;
	cout << setw(2) << setfill(c) << c << endl;
	cout << setw(38) << setfill(probel) << probel;
	cout << setw(4) << setfill(c) << c << endl;
	cout << setw(37) << setfill(probel) << probel;
	cout << setw(6) << setfill(c) << c << endl;
	cout << setw(36) << setfill(probel) << probel;
	cout << setw(8) << setfill(c) << c << endl;
	cout << setw(35) << setfill(probel) << probel;
	cout << setw(10) << setfill(c) << c << endl;
	cout << setw(34) << setfill(probel) << probel;
	cout << setw(12) << setfill(c) << c << endl;
	cout << setw(33) << setfill(probel) << probel;
	cout << setw(14) << setfill(c) << c << endl;
	cout << setw(38) << setfill(probel) << probel;
	cout << setw(4) << setfill(c) << c << endl;
	cout << setw(38) << setfill(probel) << probel;
	cout << setw(4) << setfill(c) << c << endl;
}
