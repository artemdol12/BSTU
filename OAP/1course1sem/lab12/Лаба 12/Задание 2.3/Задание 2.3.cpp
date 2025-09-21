#include <iostream> 
using namespace std;
void main()
{   int a = 99;
const int* const pa = &a;
int b = 44;
cout << "pa = " << pa << "\n";
cout << "*pa = " << *pa;
}
