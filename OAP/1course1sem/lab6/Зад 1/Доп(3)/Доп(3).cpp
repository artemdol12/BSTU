#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string k;
    cout << "Введите число: ";
    cin >> k;
    string m;//запрашиваем новую переменную для записи результата
    for (char d : k)//с помощью цикла for находим в исходном числе 3 и 6 и удаляем их
    {
        if (d != '3' && d != '6')
        {
            m += d;
        }
    }
    cout << "Вывести результат: " << m << endl;//вывести результат в консоль
}
