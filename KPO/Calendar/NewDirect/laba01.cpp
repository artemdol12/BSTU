#include <iostream> 
#include <iomanip> 
#include <string> 
#include <ctime> 

using namespace std;
int daysRemaining;
int days;
bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int dayOfYear(int day, int month, int year) {
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear(year)) {
		daysInMonth[1] = 29;
	}
	int days = 0;
	for (int m = 0; m < month - 1; ++m) {
		days += daysInMonth[m];
	}
	days += day;

	return days;
}



int main()
{
	setlocale(LC_ALL, "Russian");

	int day, month, year, date, birthdate, option, birthDay, birthdayMonth, daysRemaining = 0, count = 1;

	cout << "Введите дату (ДДММГГГГ): ";

	cin >> date;

	day = date / 1000000;

	month = (date / 10000) % 100;

	year = date % 10000;

	cout << "Введите дату рождения (ДДММ): ";

	cin >> birthdate;

	birthDay = birthdate / 100;

	birthdayMonth = birthdate % 100;

	daysRemaining = dayOfYear(birthDay, birthdayMonth, year) - dayOfYear(day, month, year);
	
	if (birthdayMonth == 2 && isLeapYear(year) ? (birthDay > 30) : (birthDay > 29)) {
		cout << "Ошибка: некорректная дата." << endl;
		return 0;
	}
	else if ((birthdayMonth == 4 || birthdayMonth == 6 || birthdayMonth == 9 || birthdayMonth == 11) && birthDay > 30) {
		cout << "Ошибка: некорректная дата." << endl;
		return 0;
	}

	if (birthdayMonth < 1 || birthdayMonth > 12 || birthDay < 1) {
		cout << "Ошибка: некорректная дата." << endl;
	}
	
	if (month == 2 && isLeapYear(year) ? (day > 30) : (day > 29)) {
		cout << "Ошибка: некорректная дата." << endl;
		return 0;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		cout << "Ошибка: некорректная дата." << endl;
		return 0;
	}

	if (month < 1 || month > 12 || day < 1) {
		cout << "Ошибка: некорректная дата." << endl;
	}
	else {
		if (isLeapYear(year)) {
			cout << "Год является високосным" << endl;
		}
		else {
			cout << "Год не является високосным" << endl;
		}
		if (daysRemaining < 0 && isLeapYear(year))
			daysRemaining = daysRemaining + 366;
		else if (daysRemaining < 0)
			daysRemaining = daysRemaining + 365;

		if (birthdayMonth == 2 && birthDay == 29) {
			if (birthdayMonth < month) {
				year++;
			}
			for (int i = 0; count >= i; i++, count++) {
				if (isLeapYear(year))
					count = 0;
				else
					year = year + 1;
				daysRemaining = daysRemaining + 365;
			}
			daysRemaining = daysRemaining - 365;
		}
		cout << "Номер дня в году: " << dayOfYear(day, month, year) << endl;
		cout << "Дней до днюхи: " << daysRemaining << endl;
	}
}