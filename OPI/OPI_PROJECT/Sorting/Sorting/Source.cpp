#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Header.h" // ���������� ������������ ����

using namespace std;

int main() {
    // �������� ������
    vector<pair<string, vector<int>>> sortedMembers = {
        {"���", {5, 5, 0, 10}},
        {"����", {5, 10, 0, 15}},
        {"����", {1, 10, 10, 21}}
    };

    // �������� ������� ��� ���������� � ������ ������
    printSortedData(sortedMembers);

    return 0;
}