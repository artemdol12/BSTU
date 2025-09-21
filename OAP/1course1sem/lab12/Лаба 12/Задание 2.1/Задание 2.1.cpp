#include <iostream> 
using namespace std;
void main()
{
	int a = 9;
	const int* pa = &a;
	pa = &a;
	int b = 20;
	pa = &b;
	cout << "pa = " << *pa;
}
