#include <iostream>
#include "Call.h"
using namespace std;

namespace Call {
	int _cdecl funcA(int a, int b, int c)
	{
		return a + b + c;
	}
	int _stdcall cstd(int& a, int b, int c)
	{
		return a * b * c;
	}
	int _fastcall cfst(int a, int b, int c, int d)
	{
		return a + b + c + d;
	}
}

int main()
{
	int value = 1;
	int result_one = Call::funcA(1, 2, 3);
	int result_two = Call::cstd(value, 2, 3);
	int result_three = Call::cfst(1, 2, 3, 4);
}