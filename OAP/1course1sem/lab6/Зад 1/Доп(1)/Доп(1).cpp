#include <iostream>
void main()
{
    setlocale(LC_CTYPE, "Russian");
    float P, Q, days = 1, m;
    printf("Торговая фирма в первый день работы реализовала товаров на P тыс. руб. Введите Р ");
    scanf_s("%f", &P);
    printf("Введите нужную выручку Q ");
    scanf_s("%f", &Q);
    m = P * (1 + 0.03);
    do
    {
        m = m * (1 + 0.03);
        days = days + 1;
    } while (m < Q);
    printf("Выручка фирмы %.3f тыс.руб.\n", m);
    printf("Количество потраченных дней %.0f\n", days);
}