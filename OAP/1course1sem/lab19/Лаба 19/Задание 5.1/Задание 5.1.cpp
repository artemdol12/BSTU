#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	int a, b, c;
	FILE* fileA = fopen("NameA.txt", "r");
	if (fileA == NULL) {
		printf("Не удалось открыть файл NameA.txt\n");
	}
	else {
		printf("Файл NameA.txt успешно открыт\n");
	}
	FILE* fileB = fopen("NameB.txt", "r");
	if (fileB == NULL) {
		printf("Не удалось открыть файл NameB.txt\n");
	}
	else {
		printf("Файл NameB.txt успешно открыт\n");
	}
	FILE* fileC = fopen("NameC.txt", "r");
	if (fileC == NULL) {
		printf("Не удалось открыть файл NameC.txt\n");
	}
	else {
		printf("Файл NameC.txt успешно открыт\n");
	}
	FILE* fileD = fopen("NameD.txt", "w");
	if (fileD == NULL) {
		printf("Не удалось открыть файл NameD.txt\n");
	}
	else {
		printf("Файл NameD.txt успешно открыт\n");
	}
	while (true) {
		int readA = fscanf(fileA, "%d", &a);
		int readB = fscanf(fileB, "%d", &b);
		int readC = fscanf(fileC, "%d", &c);
		if (readA == EOF || readB == EOF || readC == EOF) {
			break;
		}
		fprintf(fileD, "%d %d %d ", a, b, c);
	}
	fclose(fileA);
	fclose(fileB);
	fclose(fileC);
	fclose(fileD);
	printf("Значения в указанном порядке записаны в файл NameD.txt\n");
	return 0;
}
