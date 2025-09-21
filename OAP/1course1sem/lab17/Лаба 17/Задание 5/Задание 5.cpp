#include <iostream>
using namespace std;

bool isPositiveRow(int**, int, int, int);  
int sumRow(int**, int, int, int);  
void subtractFromMatrix(int**, int, int, int);  

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

    bool found = false;
    int sumPositiveRow = 0;

    for (i = 0; i < 5 && !found; i++)
    {
        if (isPositiveRow(matr, i, 4, 4))
        {
            sumPositiveRow = sumRow(matr, i, 4, 4);
            found = true;
        }
    }

    // Если строка найдена, уменьшаем все элементы матрицы
    if (found)
    {
        cout << "S = " << sumPositiveRow << endl;
        subtractFromMatrix(matr, 5, 4, sumPositiveRow);
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cout << matr[i][j] << ' ';
        }
        cout << endl;
    }

    for (i = 0; i < 5; i++)
        delete[] matr[i];
    delete[] matr;

    return 0;
}

bool isPositiveRow(int** matr, int row, int cols, int m)
{
    for (int j = 0; j < m; j++)
    {
        if (matr[row][j] <= 0)
            return false;
    }
    return true;
}

int sumRow(int** matr, int row, int cols, int m)
{
    int sum = 0;
    for (int j = 0; j < m; j++)
    {
        sum += matr[row][j];
    }
    return sum;
}

void subtractFromMatrix(int** matr, int n, int m, int sum)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matr[i][j] -= sum;
        }
    }
}
