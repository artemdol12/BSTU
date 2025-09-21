#include <iostream>
// DolnikovArtem2006
// Windows-1251 44 6F 6C 6E 69 6B 6F 76 41 72 74 65 6D 32 30 30 36
// UTF-8 44 6F 6C 6E 69 6B 6F 76 42 72 74 65 6D 32 30 30 36
// UTF-16 0044 006F 006C 006E 0069 006B 006F 0076 0042 0072 0074 0065 006D 0032 0030 0030 0036
// ДольниковАртёмАлександрович2006
// Windows-1251 C4 EE EB FC ED E8 EA EE E2 C0 F0 F2 E5 EC C0 EB E5 EA F1 E0 ED E4 F0 EE E2 E8 F7 32 30 30 36
// UTF-8 D0 94 D0 BE D0 BB D1 8C D0 BD D0 B8 D0 BA D0 BE D0 B2 D0 90 D1 80 D1 82 D1 91 D0 BC D0 90 D0 BB D0 B5 D0 BA D1 81 D0 B0 BD D0 84 D1 80 D0 BE D0 B2 D0 B8 D1 87 32 30 30 36
// UTF-16 0414 043E 043B 044C 043D 0438 043A 043E 0432 0410 0440 0442 0435 043C 0410 043B 0435 043A 0441 0431 043D 0434 0440 043E 0432 0438 0447 0032 0030 0030 0036
//Дольников2006Artem
// Windows-1251 C4 EE EB FC ED E8 EA EE E2 32 30 30 36 41 72 74 65 6D
// UTF-8 D0 94 D0 BE D0 BB D1 8C D0 BD D0 B8 D0 BA D0 BE D0 B2 32 30 30 36 41 72 74 65 6D
// UTF-16 0414 043E 043B 044C 043D 0438 043A 043E 0432 0032 0030 0030 0036 0041 0072 0074 0065 006D
int main()
{
	int number = 0x12345678;
	char hello[] = "Hello, ";
	char lfie[] = "DolnikovArtem2006";
	char rfie[] = "ДольниковАртёмАлександрович2006";
	char lr[] = "Дольников2006Artem";

	wchar_t Lfie[] = L"DolnikovArtem2006";
	wchar_t Rfie[] = L"ДольникоАртёмАлександрович2006";
	wchar_t LR[] = L"Дольников2006Artem";
	
	std::cout << hello << lfie << std::endl;
	return 0;
}
