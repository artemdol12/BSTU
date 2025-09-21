#include <iostream>
using namespace std;

struct Item {
    int data;
    Item* next;
};

Item* head = NULL;
Item* tail = NULL;

bool isNull() {
    return (head == NULL);
}

void deletFirst() {
    if (isNull()) cout << "Очередь пуста" << endl;
    else {
        Item* p = head;
        head = head->next;
        delete p;
        if (head == NULL) tail = NULL;
    }
}

void deletLast() {
    if (isNull()) {
        cout << "Очередь пуста" << endl;
        return;
    }
    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }
    Item* p = head;
    while (p->next != tail) {
        p = p->next;
    }
    delete tail;
    tail = p;
    tail->next = NULL;
}

void getFromHead() {
    if (isNull()) cout << "Очередь пуста" << endl;
    else cout << "Начало = " << head->data << endl;
}

void insertMinLIFO(int x) {
    Item* newItem = new Item{ x, NULL };
    if (isNull()) {
        head = tail = newItem;
        return;
    }
    Item* p = head;
    Item* prev = NULL;
    while (p != NULL && x > p->data) {
        prev = p;
        p = p->next;
    }
    while (p != NULL && x == p->data) {
        prev = p;
        p = p->next;
    }
    if (prev == NULL) {
        newItem->next = head;
        head = newItem;
    }
    else {
        newItem->next = prev->next;
        prev->next = newItem;
    }
    if (newItem->next == NULL) tail = newItem;
}

void insertMaxFIFO(int x) {
    Item* newItem = new Item{ x, NULL };
    if (isNull()) {
        head = tail = newItem;
        return;
    }
    Item* p = head;
    Item* prev = NULL;
    while (p != NULL && x < p->data) {
        prev = p;
        p = p->next;
    }
    while (p != NULL && x == p->data) {
        prev = p;
        p = p->next;
    }
    if (prev == NULL) {
        newItem->next = head;
        head = newItem;
    }
    else {
        newItem->next = prev->next;
        prev->next = newItem;
    }
    if (newItem->next == NULL) tail = newItem;
}

void printQueue() {
    if (isNull()) {
        cout << "Очередь пуста" << endl;
        return;
    }
    Item* p = head;
    cout << "Очередь = ";
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

void clrQueue() {
    while (!isNull()) deletFirst();
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    int choice = 1, z;
    int strategy = 1;

    cout << "Выберите стратегию:\n";
    cout << "1 - Мин. приоритет, LIFO, удаление с начала\n";
    cout << "2 - Макс. приоритет, FIFO, удаление с начала\n";
    cout << "3 - Мин. приоритет, LIFO, удаление с конца\n";
    cout << "4 - Макс. приоритет, FIFO, удаление с конца\n";
    cin >> strategy;

    while (choice != 0) {
        cout << "\n1 - добавить элемент" << endl;
        cout << "2 - получить элемент с начала" << endl;
        cout << "3 - извлечь элемент" << endl;
        cout << "4 - вывести элементы" << endl;
        cout << "5 - очистить очередь" << endl;
        cout << "0 - выход" << endl;
        cout << "Выберите действие: ";  cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите элемент: "; cin >> z;
            if (strategy == 1 || strategy == 3)
                insertMinLIFO(z);
            else if (strategy == 2 || strategy == 4)
                insertMaxFIFO(z);
            printQueue();
            break;
        case 2:
            getFromHead();
            break;
        case 3:
            if (strategy == 1 || strategy == 2)
                deletFirst();
            else
                deletLast();
            break;
        case 4:
            printQueue();
            break;
        case 5:
            clrQueue();
            break;
        }
    }
    return 0;
}
