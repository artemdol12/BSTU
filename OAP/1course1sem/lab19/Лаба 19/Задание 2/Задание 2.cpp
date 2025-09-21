#include <iostream>
#include <stdio.h>  

int main()
{
    setlocale(LC_ALL, "Russian");
    FILE* mf;
    char str[50];
    errno_t err;
    char* estr;
    printf("Введите текст: ");
    fgets(str, sizeof(str), stdin);
    err = fopen_s(&mf, "tst.txt", "w");
    if (err != 0) {  // Если ошибка при открытии файла
        printf("Ошибка открытия файла для записи\n");
        return -1;
    }
    fputs(str, mf);
    fputs("\n", mf);
    fclose(mf);

    // Открытие файла для чтения
    err = fopen_s(&mf, "tst.txt", "r");
    if (err != 0) {  // Если ошибка при открытии файла для чтения
        printf("Ошибка открытия файла для чтения\n");
        return -1;
    }
    printf("\nСчитанные строки:\n");

    while ((estr = fgets(str, sizeof(str), mf)) != NULL) {  
        puts(str);  
    }
    if (feof(mf)) {
        printf("\nЧтение файла завершено.\n");
    }
    else {
        printf("\nОшибка чтения из файла.\n");
        fclose(mf);
        return -1;
    }
    if (fclose(mf) == EOF) {
        printf("Ошибка закрытия файла\n");
        return -1;
    }

    return 0;
}
