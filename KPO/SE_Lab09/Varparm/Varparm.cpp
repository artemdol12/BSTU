#include <iostream>
#include "Varparm.h"
using namespace Varparm;
namespace Varparm
{
	int ivarparm(int a, ...)
	{
		int result = 1;
		va_list args;
		va_start(args, a);
		for (int i = 0; i < a; ++i) {
			result *= va_arg(args, int);
		}
		va_end(args);
		return result;
	}

	int svarparm(short a, ...)
	{
		int max = 0;
		va_list args;
		va_start(args, a);
		for (int i = 0; i < a; i++) {
			int value = va_arg(args, int);
			if (value > max) {
				max = value;
			}
		}
		va_end(args);
		return max;
	}

	double fvarparm(float a, ...)
	{
		double sum = 0;
		va_list args;
		va_start(args, a);
		float val = a;
		while (val != FLT_MAX) {
			sum += val;
			val = va_arg(args, double);
		}
		va_end(args);
		return sum;
	}

	double dvarparm(double a, ...)
	{
		double sum = 0;
		va_list args;
		va_start(args, a);
		double val = a;
		while (val != DBL_MAX) {
			sum += val;
			val = va_arg(args, double);
		}
		va_end(args);
		return sum;
	}
}
int main()
{
	setlocale(LC_ALL, "RU");

	int result_one = ivarparm(1, 2);
	int result_two = ivarparm(2, 7, 4);
	int result_three = ivarparm(3, 4, 3, 5);
	int result_four = ivarparm(7, 6, 3, 2, 1, 7, 5, 3);
	cout << "Результаты четырёх вычеслений: " << endl;
	cout << result_one << " " << result_two << " " << result_three << " " << result_four << endl;

	int max_one = svarparm(1, 4);
	int max_two = svarparm(2, 8, 6);
	int max_three = svarparm(3, 6, 8, 12);
	int max_four = svarparm(7, 3, 2, 7, 8, 9, 2, 1);
	cout << "Результаты четырёх вычеслений: " << endl;
	cout << max_one << " " << max_two << " " << max_three << " " << max_four << endl;

	double sum_float_one = fvarparm(FLT_MAX);
	double sum_float_two = fvarparm(2.5, FLT_MAX);
	double sum_float_three = fvarparm(5.3, 3.2, FLT_MAX);
	double sum_float_four = fvarparm(5.3, 3.2, 7.3, 8.6, 3.2, 6.4, FLT_MAX);
	cout << "Результаты четырёх вычеслений: " << endl;
	cout << sum_float_one << " " << sum_float_two << " " << sum_float_three << " " << sum_float_four << endl;

	double sum_double_one = dvarparm(DBL_MAX);
	double sum_double_two = dvarparm(6.3, DBL_MAX);
	double sum_double_three = dvarparm(5.9, 6.3, DBL_MAX);
	double sum_double_four = dvarparm(4.1, 3.3, 8.1, 2.5, 1.6, 9.3, DBL_MAX);
	cout << "Результаты четырёх вычеслений: " << endl;
	cout << sum_double_one << " " << sum_double_two << " " << sum_double_three << " " << sum_double_four << endl;
	return 0;
}