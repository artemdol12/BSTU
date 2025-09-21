#include <fstream>
#include <iostream>
#include <cctype>
using namespace std;

int main() 
{
    char a[255];
    setlocale(LC_ALL, "rus");
    char buff[255];
    ofstream fout("FILE1.txt");
    cout << "Введите строку: ";
    cin.getline(a, 255);
    fout << a;
    fout.close();

    ifstream fin1("FILE1.txt");
    fin1.getline(buff, 255);
    fin1.close();

    ofstream fin("FILE2.txt");
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        for (int i = 0; buff[i] != '\0'; i++) 
        {
            if (!isdigit(buff[i])) 
            {
                fin << buff[i]; 
                cout << buff[i]; 
            }
        }
        cout << endl;
    }
    fin.close();

    return 0;
}

