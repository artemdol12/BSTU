// myStack.cpp
#include <iostream>
#include <fstream>
#include "myStack.h"
using namespace std;

void push(int x, Stack*& myStk)   //Добавление элемента х в стек    
{
    Stack* e = new Stack;    //выделение памяти для нового элемента
    e->data = x;             //запись элемента x в поле data 
    e->next = myStk;         //перенос вершины на следующий элемент 
    myStk = e;               //сдвиг вершины на позицию вперед
}

int pop(Stack*& myStk)   //Извлечение (удаление) элемента из стека
{
    if (myStk == NULL)
    {
        cout << "Стек пуст!" << endl;
        return -1;               //если стек пуст - возврат (-1) 
    }
    else
    {
        Stack* e = myStk;     //е-переменная для хранения адреса элемента
        int x = myStk->data;  //запись элемента из поля data в перем. x 
        myStk = myStk->next;   //перенос вершины
        delete e;
        return x;
    }
}

void toFile(Stack*& myStk) //Запись в файл
{
    Stack* e = myStk;
    Stack buf;
    ofstream frm("mStack.dat");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (e)
    {
        buf = *e;
        frm.write((char*)&buf, sizeof(Stack));
        e = e->next;
    }
    frm.close();
    cout << "Стек записан в файл mStack.dat\n";
}

void fromFile(Stack*& myStk)          //Считывание из файла
{
    Stack buf, * p = nullptr, * e = nullptr;
    ifstream frm("mStack.dat");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    frm.seekg(0);
    frm.read((char*)&buf, sizeof(Stack));
    while (!frm.eof())
    {
        push(buf.data, e);
        frm.read((char*)&buf, sizeof(Stack));
    }
    frm.close();
    while (e != NULL)
    {
        buf.data = pop(e);
        push(buf.data, p);
    }
    myStk = p;
    cout << "\nСтек считан из файла mStack.dat\n\n";
}

void show(Stack*& myStk)
{
    if (myStk == NULL) {
        cout << "Стек пуст!" << endl;
        return;
    }
    Stack* temp = NULL;
    // First reverse the stack to show it in correct order
    while (myStk != NULL) {
        int x = pop(myStk);
        cout << x << " ";
        push(x, temp);
    }
    // Restore the original stack
    while (temp != NULL) {
        int x = pop(temp);
        push(x, myStk);
    }
    cout << endl;
}

int pop1(Stack*& myStk) {
    if (myStk == NULL) {
        cout << "Стек пуст!" << endl;
        return 0;
    }

    Stack* temp = NULL;
    int result = 0;
    bool found = false;

    while (myStk != NULL) {
        int x = pop(myStk);
        if (!found && x > 0) {
            result = x;
            found = true;
        }
        else {
            push(x, temp);
        }
    }

    while (temp != NULL) {
        int x = pop(temp);
        push(x, myStk);
    }

    if (found) {
        cout << "Удалён положительный элемент: " << result << endl;
    }
    else {
        cout << "В стеке нет положительных элементов!" << endl;
    }

    return result;
}

int pop100(Stack*& myStk) {
    if (myStk == NULL) {
        cout << "Стек пуст!" << endl;
        return -1;
    }

    Stack* temp = NULL;  
    int removedValue = -1;
    bool found = false;

    while (myStk != NULL && !found) {
        int x = pop(myStk);
        if (x > 100 && !found) {
            removedValue = x;
            found = true;
        }
        else {
            push(x, temp);
        }
    }

    while (temp != NULL) {
        int x = pop(temp);
        push(x, myStk);
    }

    if (found) {
        cout << "Удален элемент: " << removedValue << endl;
    }
    else {
        cout << "Элемент > 100 не найден" << endl;
    }

    return removedValue;
}