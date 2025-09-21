﻿#include <iostream>   
#include <stdio.h>       
int main(void)
{
	setlocale(LC_CTYPE, "Russian");
	FILE* fp;
	errno_t err;
	char const* st = "привет";
	err = fopen_s(&fp, "a.bin", "w");
	if (err != 0)
	{
		perror("ошибка открытия a.txt");
		return EXIT_FAILURE;
	}
	fwrite(st, strlen(st), 1, fp);
	printf("Записан элемент\n");
	fclose(fp);

	err = fopen_s(&fp, "a.bin", "r");
	if (err != 0)
	{
		perror("Невозможно открыть файл для чтения\n");
		return EXIT_FAILURE;
	}
	printf("Содержимое файла a.txt:\n");

	char buffer[256];
	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		printf("%s", buffer);
	}
	fclose(fp);
	return 0;
}
