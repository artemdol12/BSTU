#include <stdio.h> 
#include <iostream> 
void main()
{
    char s[256];
    int i, count;
    using namespace std;
    setlocale(LC_CTYPE, "Russian");
    puts("Enter string: ");
    gets_s(s);
    cout << "Текст в *...* " << endl;
    for (count = i = 0; s[i] != 0; i++)
        if (s[i] == '*') {
            for (i = i + 1;s[i] != '*'; i++) {
                cout << s[i];
            }
        }
}