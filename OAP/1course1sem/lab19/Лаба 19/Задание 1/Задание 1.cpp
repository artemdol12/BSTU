#include <stdio.h>
#include <iostream>
#include <cstdlib>

int main()
{
    setlocale(LC_ALL, "");
    int a;
    errno_t err;
    FILE* f;
    err = fopen_s(&f, "a.txt", "w");
    if (err != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }
    
    for (a = 0; a < 70; a += 3)
    {
        fprintf(f, "%d, ", a);
    }
    printf("Данные записаны в файл a.txt\n");
    fclose(f);
    
    err = fopen_s(&f, "a.txt", "r");
    if (err != 0)
    {
        perror("Невозможно открыть файл для чтения\n");
        return EXIT_FAILURE;
    }
    printf("Содержимое файла a.txt:\n");

    char buffer[256];  
    while (fgets(buffer, sizeof(buffer), f) != NULL)
    {
        printf("%s", buffer);  
    }
    fclose(f);
    return 0;
}
