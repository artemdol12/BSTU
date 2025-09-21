#include <iostream> 
using namespace std;
void main()
{
    int a = 99;
    int* const pa = &a;
    int b = 44;
    *pa = 12;
    cout << "*pa = " << *pa << "\n";
    cout << " pa = " << pa;
}
