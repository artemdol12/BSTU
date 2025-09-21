#include "functions.h"
#include "stdafx.h"

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