#include <iostream>
void main()
{
	int val = 1;
	std::cout << "value = " << val;
	int& rv = val;
	rv = 5;
	std::cout << " value = " << val;
}
