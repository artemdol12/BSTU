#pragma once
struct Stack
{
    int data;
    Stack* next;
};
void show(Stack*& myStk);
int pop(Stack*& myStk);
void push(int x, Stack*& myStk);
void toFile(Stack*& myStk);
void fromFile(Stack*& myStk);
int pop1(Stack*& myStk);
int pop100(Stack * &myStk);