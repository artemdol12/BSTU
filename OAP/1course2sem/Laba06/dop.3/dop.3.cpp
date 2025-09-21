#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

struct list
{
    float number;
    list* next;
};

void insert(list*& head, int value);
void printList(list* head);
int del(list*& head, int value);
bool find(list*& head, int value);
void toFile(list*& head);
void fromFile(list*& head);
void sum(list* head);
void menu(void);

int main()
{
    setlocale(LC_ALL, "rus");

    list* first = nullptr;
    int choice, value;

    menu();
    cout << " ? ";
    cin >> choice;

    while (choice != 8)
    {
        switch (choice)
        {
        case 1:
            cout << "Введите число: ";
            cin >> value;

            insert(first, value);
            printList(first);
            break;

        case 2:
            cout << "Введите удаляемое число: ";
            cin >> value;

            if (del(first, value))
            {
                cout << "Удаленное число " << value << endl;
                printList(first);
            }
            else
            {
                cout << "Число не найдено" << endl;
            }

            break;

        case 3:
            cout << "Введите число для поиска: ";
            cin >> value;

            if (find(first, value))
            {
                cout << "Есть такое число в списке" << endl;
            }
            else
            {
                cout << "Такого числа нету" << endl;
            }

            break;

        case 4:
            printList(first);
            break;

        case 5:
            toFile(first);
            break;

        case 6:
            fromFile(first);
            break;

        case 7:
            sum(first);
            break;

        default:
            cout << "Неправильный выбор" << endl;
            menu();
            break;
        }
        cout << " ?  ";
        cin >> choice;
    }
}

void insert(list*& head, int value)
{
    list* newNode = new list;
    newNode->number = value;
    newNode->next = head;
    head = newNode;
}

void printList(list* head)
{
    if (head == nullptr)
    {
        cout << "Список пуст" << endl;
    }
    else
    {
        cout << "Список: ";

        while (head != nullptr)
        {
            cout << "-->" << head->number;
            head = head->next;
        }
        cout << "-->nullptr" << endl;
    }
}

int del(list*& head, int value)
{

    if (head == nullptr)
    {
        return 0;
    }

    list* previous, * current, * temp;

    if (value == head->number)
    {
        temp = head;
        head = head->next;
        delete temp;

        return value;
    }
    else
    {
        previous = head;
        current = head->next;

        while (current != nullptr && current->number != value)
        {
            previous = current;
            current = current->next;
        }

        if (current != nullptr)
        {
            temp = current;
            previous->next = current->next;

            delete temp;

            return value;
        }
    }
    return 0;
}

bool find(list*& head, int value)
{
    list* current;
    bool flag = false;

    current = head;
    while (current != nullptr)
    {
        if (current->number == value)
        {
            flag = true;
            break;
        }

        current = current->next;
    }

    return flag;
}
void toFile(list*& head)
{
    ofstream file("List.txt");
    if (!file.is_open())
    {
        cout << "Ошибка при открытии файла" << endl;
        return;
    }

    list* temp = head;
    while (temp != nullptr)
    {
        file << temp->number << " ";
        temp = temp->next;
    }

    file.close();
    cout << "Список записан в файл List.txt" << endl;
}

void fromFile(list*& head)
{
    while (head != nullptr) // Очисть список чтобы туда записать элементы из файла
    {
        list* temp = head;
        head = head->next;
        delete temp;
    }

    ifstream file("List.txt");
    if (!file.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
        return;
    }

    int value;
    list* first = nullptr;

    while (file >> value)
    {
        insert(first, value); // Добавление числа в списко
        cout << "-->" << value;
    }

    if (first == nullptr)
    {
        cout << "Файл пуст или содержит некорректные данные" << endl;
    }
    else
    {
        cout << "-->nullptr" << endl;
    }

    file.close();

    head = first; // Присваиваем новый список
    cout << "Список успешно загружен из файла List.txt" << endl;
}

void sum(list* head)
{
    int suma = 0;
    int schet = 0;
    float medium = 0;
    if (head == nullptr)
    {
        cout << "Список пуст" << endl;
        return;
    }
    else
    {
        while (head != nullptr)
        {
            if (head->number < 0 ) 
            {
                schet++;
                suma = suma + (head->number);
            }

            head = head->next;
        }
        medium = suma / schet;
            cout << "Среднее значение отрицательных = " << medium << endl;
    }
}

void menu()
{
    cout << "Сделай выбор: " << endl;
    cout << "1-Ввод элемента" << endl;
    cout << "2-Удаление элемента" << endl;
    cout << "3-Поиск элемента" << endl;
    cout << "4-Вывод списка" << endl;
    cout << "5-Запись в файл" << endl;
    cout << "6-Считывание из файла" << endl;
    cout << "7-Расчитать сумму положительных элементов" << endl;
    cout << "8-Выход" << endl;
}