#include <stdio.h>  
#include <fstream>  
#include <cstring>  
using namespace std; 
int countVowels(const char* str) {
    int count = 0;
    const char* vowels = "aeiouAEIOU";
    while (*str) {   
        if (strchr(vowels, *str)) {
            count++;
        }
        str++;
    }
    return count;
}
int main() {
    int k, vowelCount, p = 0;
    FILE* fin;
    fopen_s(&fin, "C:\\Уник\\OAIP\\1course2sem\\Laba3\\FILE1.txt", "rt");
    ofstream fout1("C:\\Уник\\OAIP\\1course2sem\\Laba3\\FILE2.txt");
    printf("Vedite 4islo k\n");
    scanf_s("%d", &k);
    int lineCount = 0;
    int schet = k + 2;  
    while (!feof(fin) && lineCount + k - 1 < schet) {
        char s[255] = "";
        if (fgets(s, sizeof(s), fin) != nullptr) {  
            fout1 << s; 
            lineCount++;  
            vowelCount = countVowels(s);
            p += vowelCount;
        }
    }
    printf("Glasnih v strokah: %d\n", p);
    fclose(fin);
    fout1.close();
    return 0;
}