#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

int main() 
{
	setlocale(LC_ALL, "rus");
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
			// определить количество целых чисел в std::vector равных заданному
	int target1 = 3;
	int num_items1 = std::count(v.begin(), v.end(), target1);
	std::cout << "Число: " << target1 << " количество: " << num_items1 << "\n";
			// лямбда-выражение для подсчета элементов, кратных 3
	int num_items3 = std::count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });
	std::cout << "количество элементов кратных 3: " << num_items3 << "\n";
	std::cout << std::endl << " Лямбда, захват переменных" << std::endl;
		// лямбда-выражение захват переменных
	for (auto i : v) [i]() {if (i % 3 == 0) std::cout << i << " ";}();

	std::cout << std::endl << " Лямда с параметрами" << std::endl;
	//Вывод значений кратных 3. Значения будем передавать как параметр у обычной функции
	for (auto i : v)[i](auto i) {if (i % 3 == 0) std::cout << i << " ";}(i);
	std::cout << std::endl << " Лямбда без параметров" << std::endl;
	// Вывод значений кратных 3
	// Значения передаются через захват переменных при этом пропустили скобки для добавления параметров
	for (auto i : v)[i] {if (i % 3 == 0) std::cout << i << " "; }();
}