#include <iostream>
#include <stdio.h>
using namespace std;

void main()
{
    setlocale(LC_CTYPE, "Russian");
    int m = 0, number = 0, pr = 0;
    long fsize;
    char pd;
    FILE* fd;
    errno_t err;
    err = fopen_s(&fd, "b.txt", "r");
    if (err != 0)
    {
        perror("ошибка открытия b.txt");
        return;
    }
    fseek(fd, 0L, SEEK_END);
    fsize = ftell(fd);
    fseek(fd, 0L, SEEK_SET);
    cout << "Введите номер предложения: ";
    cin >> number;

    // Чтение всего файла и вывод предложений с 1 по n
    int currentSentence = 1;
    while (ftell(fd) < fsize && currentSentence <= number)
    {
        m = 0;
        long startPos = ftell(fd);
        while (fread(&pd, sizeof(char), 1, fd) && pd != '.')
        {
            m++;
        }
        if (m > 0)
        {
            cout << currentSentence << "-е предложение: ";
            fseek(fd, startPos, SEEK_SET);
            for (int i = 0; i < m + 1; i++)
            {
                fread(&pd, sizeof(char), 1, fd);
                cout << pd;
            }
            cout << endl;
            currentSentence++;
        }
    }
    if (number < 1 || number > currentSentence - 1)
    {
        printf("Такого номера предложения нет\n");
    }

    fclose(fd);
}
