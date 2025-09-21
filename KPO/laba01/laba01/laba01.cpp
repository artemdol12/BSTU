#include <iostream>
#include <windows.h>
using namespace std;

int sum(int x, int y) { return x + y; };
int sub(int x, int y) { return x - y; };

int(*func)(int, int);

int main()
{

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int n = 3;
	int X = 9 + n, Y = 10 + n, Z = 11 + n;
	float S = 1.0 + n;

	bool question4_1 = false; // 00 
	bool question4_2 = true; // 01 

	char question5 = 'o'; // 6f
	char question6 = 'о'; // FFFF FFFF FFFF FFEE

	wchar_t question7 = L'D'; // 44
	wchar_t question8 = L'Д';// 414

	short question9_1 = X; //C
	short question9_2 = -X; //FFFF FFFF FFFF FFF4

	short question10_1 = 0x7FFF;//32767
	short question10_2 = 0xFFFFFFFFFFFF8000;//-32768

	unsigned short question11_1 = 0xFFFF; //65535
	unsigned short question11_2 = 0;// 0

	int question12_1 = Y;// D
	int question12_2 = -Y;// FFFF FFFF FFFF FFF3

	int question13_1 = 0x7FFFFFFF;// 2147483647
	int question13_2 = 0xFFFFFFFF80000000;// -2147483648

	unsigned int question14_1 = 0xFFFFFFFF;// 4294967295
	unsigned int question14_2 = 0;// 0

	long question15_1 = Z;// E
	long question15_2 = -Z;// FFFF FFFF FFFF FFF2

	long question16_1 = 0x7FFFFFFF;// 2147483647
	long question16_2 = 0xFFFFFFFF80000000;// -2147483648

	unsigned long question17_1 = 0xFFFFFFFF;// 4294967295
	unsigned long question17_2 = 0;// 0

	float question18_1 = S;// 0x40800000
	float question18_2 = -S;//0xC0800000

	float question19_1 = S / 0;// inf
	float question19_2 = -S / 0;// -inf
	float question19_3 = question19_1 / question19_2;//-ind

	char question20_1 = 'd';// 64
	wchar_t question20_2 = L'а';// 430
	short question20_3 = 15;// F 
	int question20_4 = 150;// 96
	float question20_5 = 150.1;// 96.199...
	double question20_6 = 150.00001;// 96.000A7C5AC...

	char* c = &question20_1;
	wchar_t* wc = &question20_2;
	short* s = &question20_3;
	int* i = &question20_4;
	float* f = &question20_5;
	double* d = &question20_6;

	char* c1 = c + 3;
	wchar_t* wc1 = wc + 3;
	short* s1 = s + 3;
	int* i1 = i + 3;
	float* f1 = f + 3;
	double* d1 = d + 3;

	func = sum;
	int x = func(2, 3);
	func = sub;
	int y = func(2, 3);

	return 0;

}