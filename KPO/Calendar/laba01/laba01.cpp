#include "functions.h"
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string getMonthName(int month) {
    string months[] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
                       "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
    if (month >= 1 && month <= 12) {
        return months[month - 1];
    }
    return "Неверный месяц";
}

void getDateFromDayOfYear(int dayOfYear, int year, int& day, int& month) {
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
    month = 1;
    while (dayOfYear > daysInMonth[month - 1]) {
        dayOfYear -= daysInMonth[month - 1];
        month++;
    }
    day = dayOfYear;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int day, month, year, date, birthdate, birthDay, birthdayMonth, daysRemaining = 0, count = 0, year1 = 0;

    cout << "Введите дату (ДДММГГГГ): ";
    cin >> date;

    day = date / 1000000;
    month = (date / 10000) % 100;
    year = date % 10000;
    year1 = date % 10000;
    if (month == 2 && (isLeapYear(year) ? (day > 29) : (day > 28))) {
        cout << "Ошибка: некорректная дата." << endl;
        return 0;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        cout << "Ошибка: некорректная дата." << endl;
        return 0;
    }
    else if (month < 1 || month > 12 || day < 1) {
        cout << "Ошибка: некорректная дата." << endl;
        return 0;
    }

    cout << "Введите дату рождения (ДДММ): ";
    cin >> birthdate;

    birthDay = birthdate / 100;
    birthdayMonth = birthdate % 100;

    daysRemaining = dayOfYear(birthDay, birthdayMonth, year) - dayOfYear(day, month, year);

    if ((birthdayMonth == 4 || birthdayMonth == 6 || birthdayMonth == 9 || birthdayMonth == 11) && birthDay > 30) {
        cout << "Ошибка: некорректная дата." << endl;
        return 0;
    }

    if (birthdayMonth < 1 || birthdayMonth > 12 || birthDay < 1) {
        cout << "Ошибка: некорректная дата." << endl;
        return 0;
    }

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
            else {
                year = year + 1;
                daysRemaining = daysRemaining + 365;
            }
        }
    }
    if (month > 2)
    cout << "Номер дня в году: " << dayOfYear(day, month, year)<< endl;
    else 
    cout << "Номер дня в году: " << dayOfYear(day, month, year) << endl;
    cout << "Дней до дня рождения: " << daysRemaining << endl;

    cout << "Месяц: " << getMonthName(month) << " (порядковый номер: " << month << ")" << endl;

    int dayOfYearInput;
    cout << "Введите порядковый номер дня года: ";
    cin >> dayOfYearInput;
    if (dayOfYearInput > 366 && isLeapYear(year) && dayOfYearInput < 0) {
        cout << "Неправильный день";
    }
    else if (dayOfYearInput > 365 && dayOfYearInput < 0) {
        cout << "Неправильный день";
    }

    int resultDay, resultMonth;
    getDateFromDayOfYear(dayOfYearInput, year1, resultDay, resultMonth);
    
    cout << "Дата, соответствующая порядковому номеру " << dayOfYearInput << ": "
        << resultDay << " " << getMonthName(resultMonth) << " " << year1 << endl;
    if ((isLeapYear(year) && dayOfYearInput == 68))
        cout << "Сегодня День женщин" << endl;
    else if (dayOfYearInput == 67 && !isLeapYear(year))
        cout << "Сегодня День женщин" << endl;
    if (dayOfYearInput == 1 || dayOfYearInput == 2)
        cout << "Сегодня Новый год" << endl;
    if ((isLeapYear(year) && dayOfYearInput == 122))
        cout << "Сегодня Праздник труда" << endl;
    else if (dayOfYearInput == 121 && !isLeapYear(year))
        cout << "Сегодня Праздник труда" << endl;
    if ((isLeapYear(year) && dayOfYearInput == 130))
        cout << "Сегодня День победы" << endl;
    else if (dayOfYearInput == 129 && !isLeapYear(year))
        cout << "Сегодня День победы" << endl;
    return 0;
}