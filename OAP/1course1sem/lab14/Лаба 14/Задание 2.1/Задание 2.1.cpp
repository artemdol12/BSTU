#include <iostream>
void main()
{
	const int n = 3, m = 2;
	int h = 0;
	int C[n][m] = { 0, 1, 2, 3, 4, 5 };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			h += *(*(C + i) + j);
	std::cout << h;
}
