#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");

    int A, B, n, p, q, m;
    int maskA, maskB, tmpA, tmpB;
    char tmp[33];
    cout << "Ввести количество бит для инвертирования (n): ";
    cin >> n;
    cout << "Ввести позицию, с которой инвертировать биты в A (p): ";
    cin >> p;
    cout << "Введите A: ";
    cin >> A;
    cout << "Введите B: ";
    cin >> B;
    cout << "Введите количество бит, которые нужно заменить (m): ";
    cin >> m;
    cout << "Введите позицию, с которой заменять биты в B (q): ";
    cin >> q;
    // Инвертирование n битов числа A, начиная с позиции p
    maskA = ((1 << n) - 1) << p;  // Маска для n бит, начиная с позиции p
    tmpA = A & maskA;  // Извлекаем n бит из A
    tmpA = ~tmpA;      // Инвертируем эти биты
    A = A & ~maskA;// Очищаем n бит в A
    A = A | (tmpA & maskA);// Вставляем инвертированные биты на их место
    _itoa_s(A, tmp, 2);
    cout << "Инвертированное A: " << tmp << endl;
    _itoa_s(B, tmp, 2);
    cout << "Вывод B: " << tmp << endl;
    maskB = ((1 << m) - 1) << q;  // Маска для m бит, начиная с позиции q
    tmpB = B & maskB;  // Извлекаем m бит из В
    A = A & ~maskB;// Очищаем m бит в A, начиная с позиции q
    A = A | tmpB;// Вставляем bиты из B на место в A
    _itoa_s(A, tmp, 2);
    cout << "Результат после замены: " << tmp << endl;

    return 0;
}
