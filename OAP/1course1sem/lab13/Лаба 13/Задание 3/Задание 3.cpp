#include <iostream>

void main()
{
    char s, t[20];
    int i, j, n;
    using namespace std;
    cout << "Input string: ";
    gets_s(t);
    cout << "Input symbol: ";
    cin >> s;
    n = strlen(t);
    for (i = 0; i <= n; i++)
        if (t[i] == s)
            for (j = i; j <= n; j++)
                t[i] = t[i + 1];
    for (i = 0; i < n; i++)
        cout << t[i];
}
