#include <iostream>
void main()
{
	using namespace std;
	float a, * pa, s = 0; int i;
	pa = &a;
	for (i = 1; i <= 4; i++)
	{
		cout << "a=";
		cin >> a;
		s += *pa;
	}
	cout << "s=" << s << endl;
}
