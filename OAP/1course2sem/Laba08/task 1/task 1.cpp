#include "MyQueue.h"
#include <iostream>
using namespace std;

struct myQue {
    int a;
    char b;
};

void printQueue(Queue& q) {
    if (q.isEmpty()) {
        cout << "Очередь пуста." << endl;
        return;
    }
    Queue temp = createQueue(q.Size - 1);
    cout << "Элементы очереди:" << endl;
    while (!q.isEmpty()) {
        myQue* item = (myQue*)peekQueue(q);
        cout << item->a << " " << item->b << endl;
        enQueue(temp, delQueue(q));
    }
    while (!temp.isEmpty()) {
        enQueue(q, delQueue(temp));
    }
    releaseQueue(temp);
}

myQue* findMax(Queue& q) {
    if (q.isEmpty()) return nullptr;
    myQue* maxItem = nullptr;
    Queue temp = createQueue(q.Size - 1);
    while (!q.isEmpty()) {
        myQue* current = (myQue*)peekQueue(q);
        if (maxItem == nullptr || current->a > maxItem->a) {
            maxItem = current;
        }
        enQueue(temp, delQueue(q));
    }
    while (!temp.isEmpty()) {
        enQueue(q, delQueue(temp));
    }
    releaseQueue(temp);
    return maxItem;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int initialSize;
    cout << "Введите максимальный размер очереди: ";
    cin >> initialSize;
    Queue q1 = createQueue(initialSize);

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить элемент\n";
        cout << "2. Вывести элементы\n";
        cout << "3. Удалить элемент\n";
        cout << "4. Определить размер очереди\n";
        cout << "5. Удалить три первых элемента\n";
        cout << "6. Вывести размер оставшейся очереди\n";
        cout << "7. Найти максимальный элемент\n";
        cout << "8. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            myQue* newItem = new myQue;  // Создаём новый элемент
            cout << "Введите целое число (a): ";
            cin >> newItem->a;
            cout << "Введите символ (b): ";
            cin >> newItem->b;

            if (!enQueue(q1, newItem)) {  // Пытаемся добавить в очередь
                cout << "Очередь полна. Не удалось добавить элемент.\n";
                delete newItem;  // Освобождаем память, если не удалось добавить
            }
            else {
                cout << "Элемент (" << newItem->a << ", " << newItem->b << ") успешно добавлен.\n";
            }
            break;
        }
        case 2: {
            printQueue(q1);
            break;
        }
        case 3: {
            myQue* removed = (myQue*)delQueue(q1);
            if (removed) {
                cout << "Удалён элемент: " << removed->a << " " << removed->b << endl;
                delete removed;
            }
            else {
                cout << "Очередь пуста.\n";
            }
            break;
        }
        case 4: {
            int size = getQueueSize(q1);
            cout << "Текущий размер очереди: " << size << endl;
            break;
        }
        case 5: {
            int count = 0;
            while (count < 3 && !q1.isEmpty()) {
                myQue* removed = (myQue*)delQueue(q1);
                delete removed;
                count++;
            }
            cout << "Удалено " << count << " элементов.\n";
            break;
        }
        case 6: {
            int size = getQueueSize(q1);
            cout << "Размер оставшейся очереди: " << size << endl;
            break;
        }
        case 7: {
            myQue* maxItem = findMax(q1);
            if (maxItem) {
                cout << "Максимальный элемент: " << maxItem->a << " " << maxItem->b << endl;
            }
            else {
                cout << "Очередь пуста.\n";
            }
            break;
        }
        case 8: {
            cout << "Выход из программы.\n";
            break;
        }
        default: {
            cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
        }
    } while (choice != 8);

    while (!q1.isEmpty()) {
        myQue* item = (myQue*)delQueue(q1);
        delete item;
    }
    releaseQueue(q1);

    return 0;
}