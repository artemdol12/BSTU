// myStack.cpp
#include <iostream>
#include <fstream>
#include "myStack.h"
using namespace std;

void push(int x, Stack*& myStk)   //���������� �������� � � ����    
{
    Stack* e = new Stack;    //��������� ������ ��� ������ ��������
    e->data = x;             //������ �������� x � ���� data 
    e->next = myStk;         //������� ������� �� ��������� ������� 
    myStk = e;               //����� ������� �� ������� ������
}

int pop(Stack*& myStk)   //���������� (��������) �������� �� �����
{
    if (myStk == NULL)
    {
        cout << "���� ����!" << endl;
        return -1;               //���� ���� ���� - ������� (-1) 
    }
    else
    {
        Stack* e = myStk;     //�-���������� ��� �������� ������ ��������
        int x = myStk->data;  //������ �������� �� ���� data � �����. x 
        myStk = myStk->next;   //������� �������
        delete e;
        return x;
    }
}

void toFile(Stack*& myStk) //������ � ����
{
    Stack* e = myStk;
    Stack buf;
    ofstream frm("mStack.dat");
    if (frm.fail())
    {
        cout << "\n ������ �������� �����";
        exit(1);
    }
    while (e)
    {
        buf = *e;
        frm.write((char*)&buf, sizeof(Stack));
        e = e->next;
    }
    frm.close();
    cout << "���� ������� � ���� mStack.dat\n";
}

void fromFile(Stack*& myStk)          //���������� �� �����
{
    Stack buf, * p = nullptr, * e = nullptr;
    ifstream frm("mStack.dat");
    if (frm.fail())
    {
        cout << "\n ������ �������� �����";
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
    cout << "\n���� ������ �� ����� mStack.dat\n\n";
}

void show(Stack*& myStk)
{
    if (myStk == NULL) {
        cout << "���� ����!" << endl;
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
        cout << "���� ����!" << endl;
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
        cout << "����� ������������� �������: " << result << endl;
    }
    else {
        cout << "� ����� ��� ������������� ���������!" << endl;
    }

    return result;
}

int pop100(Stack*& myStk) {
    if (myStk == NULL) {
        cout << "���� ����!" << endl;
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
        cout << "������ �������: " << removedValue << endl;
    }
    else {
        cout << "������� > 100 �� ������" << endl;
    }

    return removedValue;
}