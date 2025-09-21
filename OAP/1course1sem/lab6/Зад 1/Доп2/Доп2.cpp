#include <iostream>
int main()
{
    setlocale(LC_CTYPE, "Russian");
    using namespace std;
    int a, b, z = 0;
    cout << "Введите последовательность чисел (заканчивается 0): ";
    cin >> a;
    while (a != 0)
    {
        cin >> b;
        if (b == 0)
        {
            break;
        }
        if ((a > 0 && b < 0) || (a < 0 && b > 0))
        {
            z = z + 1;
        }
        a = b;
    }
    cout << "Количество изменений знака: " << z << endl;
    return 0;
}