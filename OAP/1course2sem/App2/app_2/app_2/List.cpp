#include "List.h"
#include <iostream>

bool Object::Insert(void* data) {
    Head = new Element(nullptr, data, Head);
    if (Head->Next != nullptr)
        Head->Next->Prev = Head;
    return true;
}

bool Object::InsertEnd(void* data) {
    if (Head == nullptr) {
        return Insert(data);
    }
    else {
        Element* last = GetLast();
        last->Next = new Element(last, data, NULL);
        return true;
    }
}

Element* Object::Search(void* data) {
    Element* rc = Head;
    while ((rc != nullptr) && (rc->Data != data))
        rc = rc->Next;
    return rc;
}

void Object::PrintList(void(*f)(void*)) {
    Element* e = Head;
    while (e != nullptr) {
        f(e->Data);
        e = e->GetNext();
    }
}

void Object::PrintList(void(*f)(void*), Element* e) {
    f(e->Data);
}

bool Object::Delete(Element* e) {
    bool rc = (e != nullptr);
    if (rc) {
        if (e->Next != nullptr)
            e->Next->Prev = e->Prev;
        if (e->Prev != nullptr)
            e->Prev->Next = e->Next;
        else
            Head = e->Next;
        delete e;
    }
    return rc;
}

bool Object::Delete(void* data) {
    return Delete(Search(data));
}

bool Object::DeleteList() {
    while (Head != nullptr) {
        Delete(Head);
    }
    return true;
}

int Object::CountList() {
    int count = 0;
    Element* e = Head;
    while (e != nullptr) {
        count++;
        e = e->GetNext();
    }
    return count;
}

Element* Object::GetLast() {
    Element* e = Head, * rc = e;
    while (e != nullptr) {
        rc = e;
        e = e->GetNext();
    }
    return rc;
}

Object Create() {
    return *(new Object());
}