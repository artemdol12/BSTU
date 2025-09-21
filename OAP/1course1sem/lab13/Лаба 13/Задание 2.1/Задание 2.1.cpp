#include <cstring>
#include <iostream>
using namespace std;

void main()
{
	char str[50], s[20];
	int i, j, i1, i2;
	cout << "Input string:";
	cin >> str;
	for (i = strlen(str); i >= 0; i--)
		if (str[i] == '\/')  break;
	i2 = i;
	for (j = (i2 - 1); j >= 0; j--)
		if (str[j] == '\/')  break;
	i1 = j;
	if (i2 == i1)
		printf(" '\/' ");
	else
	{
		strncpy_s(s, &str[i1 + 1], i2 - i1 - 1);
		s[i2 - i1 - 1] = 0;
		cout << "katalog:" << s << "\n";
	}
}
