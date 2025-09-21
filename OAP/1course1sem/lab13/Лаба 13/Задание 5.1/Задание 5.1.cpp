#include <stdio.h>
void main()
{
	char s[256];
	int count;
	char* ps;
	puts("Enter string: ");
	gets_s(s);
	for (count = 0, ps = s; *ps != 0; ps++)
	{
		if (*ps == '(')  count++;
		if (*ps == ')')  count--;
	}
	if (count == 0)
		puts("Ok\n");
	else
		puts("Not Ok\n");
}
