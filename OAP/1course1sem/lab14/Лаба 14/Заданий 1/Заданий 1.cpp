#include <iostream> 
void main()
{
    const int ci = 3;
    const int cj = 2;
    int a[ci][cj] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };

    for (int i = 0; i < ci; i++) {
        for (int j = 0; j < cj; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
