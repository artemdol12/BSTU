#include <iostream>
#include <iomanip> 
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int n, i, j;
	printf("Enter n: ");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			printf("%5d \n", i * j);
		if (i == 1)
		{
			cout << endl;
			cout << setw(5 * n) << setfill('-') <<
				'-' << endl;
			printf(" Результат \n");
		}
	}
}
