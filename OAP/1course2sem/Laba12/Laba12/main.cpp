﻿#include "Heap.h"
#include <iostream>
using namespace std;
heap::CMP cmpAAA(void* a1, void* a2)  //Функция сравнения
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(30, cmpAAA);
	for (;;)
	{
		cout << "1 - вывод первой кучи на экран" << endl;
		cout << "2 - вывод второй кучи на экран" << endl;
		cout << "3 - добавить элемент в первую кучу" << endl;
		cout << "4 - добавить элемент во вторую кучу" << endl;
		cout << "5 - удалить максимальный элемент из первой кучи" << endl;
		cout << "6 - удалить минимальный элемент из первой кучи" << endl;
		cout << "7 - удалить i-ый элемент из первой кучи" << endl;
		cout << "8 - объединить две кучи" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1:  h1.scan(0);
			break;
		case 2:
			h2.scan(0);
			break;
		case 3: {
			AAA* a = new AAA;
			cout << "введите ключ" << endl; 	cin >> k;
			a->x = k;
			h1.insert(a);
		}
			  break;
		case 4: {
			AAA* a = new AAA;
			cout << "введите ключ для второй кучи" << endl;
			cin >> k;
			a->x = k;
			h2.insert(a);
			break;
		}
		case 5:   h1.extractMax();
			break;
		case 6:   h1.extractMin();
			break;
		case 7: {
			h1.extractI();
			break;
		}
		case 8: {
			h1.unionHeap(h2);
			cout << "Кучи объединены!" << endl;
			break;
		}
		default:  cout << endl << "Введена неверная команда!" << endl;
		}
	} return 0;
}
