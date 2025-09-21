#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Header.h" // Подключаем заголовочный файл

using namespace std;

int main() {
    // Исходные данные
    vector<pair<string, vector<int>>> sortedMembers = {
        {"Аня", {5, 5, 0, 10}},
        {"Ваня", {5, 10, 0, 15}},
        {"Саня", {1, 10, 10, 21}}
    };

    // Вызываем функцию для сортировки и вывода данных
    printSortedData(sortedMembers);

    return 0;
}