#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    setlocale(LC_CTYPE, "Russian");
    char c;
    char p = ' ';
    cout << "Вести символ:";
    cin >> c;
    cout << setw(35) << setfill(p) << p;
    cout << setw(8) << setfill(c) << c << endl;
    cout << setw(31) << setfill(p) << p;
    cout << setw(16) << setfill(c) << c << endl;
    cout << setw(29) << setfill(p) << p;
    cout << setw(20) << setfill(c) << c << endl;
    cout << setw(28) << setfill(p) << p;
    cout << setw(22) << setfill(c) << c << endl;
    cout << setw(27) << setfill(p) << p;
    cout << setw(24) << setfill(c) << c << endl;
    cout << setw(27) << setfill(p) << p;
    cout << setw(24) << setfill(c) << c << endl;
    cout << setw(27) << setfill(p) << p;
    cout << setw(24) << setfill(c) << c << endl;
    cout << setw(27) << setfill(p) << p;
    cout << setw(24) << setfill(c) << c << endl;
    cout << setw(28) << setfill(p) << p;
    cout << setw(22) << setfill(c) << c << endl;
    cout << setw(29) << setfill(p) << p;
    cout << setw(20) << setfill(c) << c << endl;
    cout << setw(31) << setfill(p) << p;
    cout << setw(16) << setfill(c) << c << endl;
    cout << setw(35) << setfill(p) << p;
    cout << setw(8) << setfill(c) << c << endl;
    return(0);
}