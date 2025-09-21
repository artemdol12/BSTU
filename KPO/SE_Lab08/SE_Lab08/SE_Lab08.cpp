#include <iostream>
using namespace std;

int defaultparm(int a, int b, int c, int d, int e, int l = 1, int m = 2)
{
	return (a + b + c + d + e + l + m) / 7;
}

int main()
{
	int result_one = defaultparm(1, 2, 3, 4, 5);
	int result_two = defaultparm(1, 2, 3, 4, 5, 6, 7);
}