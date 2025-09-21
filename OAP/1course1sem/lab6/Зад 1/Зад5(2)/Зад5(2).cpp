#include <iostream>
void main()
{
    setlocale(LC_CTYPE, "Russian");
    float z, q, y, x, j, a, sd;
    y = -1.55;
    a = 6;
    j = -1;
    while (j < 1)
    {
        z = sqrt(a + 1) - tan(j + y);
        q = exp(-j * 0.1 * y) + pow(3 * z, 2);
        printf("j = %5.2f\t", j);
        printf("q = %5.2f\n", q);
        j = j + 0.2;
    }
}
