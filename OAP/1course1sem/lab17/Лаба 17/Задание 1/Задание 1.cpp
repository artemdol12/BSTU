#include <iostream>
using namespace std;

int sum(int**, int, int);

int main()
{
    int i, j;
    int** matr = new int* [5];
    for (i = 0; i < 5; i++)
        matr[i] = new int[4];
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            matr[i][j] = i + j;
            cout << matr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "S=" << sum(matr, 5, 4) << endl;
    for (int i = 0; i < 5; i++)
        delete matr[i];
    delete[] matr;
}

int sum(int** x, int n, int m)
{
    int res = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            res += x[i][j];
    return res;
}
