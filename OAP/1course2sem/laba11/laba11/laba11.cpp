#include <iostream>
#include <queue>
using namespace std;
struct Tree          //дерево
{
    int key;         //ключ
    char text[10];    //текст - не более 4 букв
    Tree* Left, * Right;
};

Tree* makeTree(Tree* Root);       //Создание дерева
Tree* list(int i, char* s);       //Создание нового элемента
Tree* insertElem(Tree* Root, int key, char* s);  //Добавление нового элемента
Tree* search(Tree* n, int key);   //Поиск элемента по ключу 
Tree* delet(Tree* Root, int key); //Удаление элемента по ключу
int view(Tree* t, int level);    //Вывод дерева 
int count(Tree* t, char letter);  //Подсчет количества слов
bool delAll(Tree* t);             //Очистка дерева
void printByLevels(Tree* root);
int countLeftChildren(Tree* root);
int countLeafNodes(Tree* node);
int countNodesWithKey(Tree* node, int k);

int c = 0;         //количество слов
Tree* Root = NULL;     //указатель на корень

void main()
{
    setlocale(0, "Russian");
    int key, choice, n;
    Tree* rc; char s[10], letter;
    for (;;)
    {
        cout << "1 -    создание дерева\n";
        cout << "2 -    добавление элемента\n";
        cout << "3 -    поиск по ключу\n";
        cout << "4 -    удаление элемента\n";
        cout << "5 -    вывод дерева\n";
        cout << "6 -    подсчет количества слов\n";
        cout << "7 -    очистка дерева\n";
        cout << "8 -    Вывод элементов по уровням\n";
        cout << "9 -    Подсчет левых дочерних вершин\n";
        cout << "10 -    подсчета листьев\n";
        cout << "11 -    Подсчет вершин с заданным значением\n";
        cout << "12 -    выход\n";
        cout << "ваш выбор?\n";
        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1:  Root = makeTree(Root);    break;
        case 2:  cout << "\nВведите ключ: ";
            cin >> key;
            cout << "Введите слово: ";
            cin >> s;
            Root = insertElem(Root, key, s); break; // Исправлено: присваиваем Root результат вставки
        case 3:  cout << "\nВведите ключ: ";
            cin >> key;
            rc = search(Root, key);
            if (rc != NULL) { // Проверка на случай отсутствия элемента
                cout << "Найденное слово= ";
                puts(rc->text);
            }
            else {
                cout << "Элемент не найден\n";
            }
            break;
        case 4:  cout << "\nВведите удаляемый ключ: ";
            cin >> key;
            Root = delet(Root, key);  break;
        case 5:  if (Root != NULL)
        {
            cout << "Дерево повернуто на 90 град. влево" << endl;
            view(Root, 0);
        }
              else cout << "Дерево пустое\n"; break;
        case 6:  cout << "\nВведите букву: ";
            cin >> letter;
            c = 0; // Сбрасываем счетчик перед подсчетом
            n = count(Root, letter);
            cout << "Количество слов, начинающихся с буквы " << letter;
            cout << " равно " << n << endl; break;
        case 7:  delAll(Root);
            Root = NULL; // После очистки обнуляем корень
            break;
        case 8:
            if (Root != NULL) {
                cout << "Дерево поуровням:\n";
                printByLevels(Root);
            }
            else {
                cout << "Дерево пустое\n";
            }
            break;
        case 9:
            if (Root != NULL) {
                int leftCount = countLeftChildren(Root);
                cout << "Количество левых дочерних вершин: " << leftCount << endl;
            }
            else {
                cout << "Дерево пустое\n";
            }
            break;
        case 10:
            if (Root != NULL) {
                int leaves = countLeafNodes(Root);
                cout << "Количество листьев: " << leaves << endl;
            }
            else {
                cout << "Дерево пустое\n";
            }
            break;
        case 11:
            if (Root != NULL) {
                int k;
                cout << "Введите значение k: ";
                cin >> k;
                int count = countNodesWithKey(Root, k);
                cout << "Количество вершин со значением " << k << ": " << count << endl;
            }
            else {
                cout << "Дерево пустое\n";
            }
            break;
        case 12:  exit(0);
        }
    }
}

Tree* makeTree(Tree* Root)    //Создание дерева
{
    int key; char s[10];
    cout << "Конец ввода - отрицательное число\n\n";
    if (Root == NULL)    // если дерево не создано
    {
        cout << "Введите ключ корня: "; cin >> key;
        cout << "Введите слово корня: "; cin >> s;
        Root = list(key, s);    // установка указателя на корень
    }
    while (1)                //добавление элементов
    {
        cout << "\nВведите ключ: ";  cin >> key;
        if (key < 0) break;       //признак выхода (ключ < 0)   
        cout << "Введите слово: ";  cin >> s;
        Root = insertElem(Root, key, s); // Исправлено: обновляем Root
    }
    return Root;
}

Tree* list(int i, char* s)     //Создание нового элемента
{
    Tree* t = new Tree;
    t->key = i;
    strncpy_s(t->text, s, 10); // Исправлено: безопасное копирование строки
    t->Left = t->Right = NULL;
    return t;
}

Tree* insertElem(Tree* Root, int key, char* s)  //Добавление нового элемента
{
    if (Root == NULL) {
        return list(key, s); // Создаем новый узел, если дерево пустое
    }

    Tree* Prev = NULL;
    Tree* current = Root;
    int find = 0;

    while (current != NULL && !find)
    {
        Prev = current;
        if (key < current->key) {
            current = current->Left;
        }
        else {
            current = current->Right;
        }
    }

    if (!find) // Если ключ не найден, добавляем новый элемент
    {
        Tree* newNode = list(key, s);
        if (key < Prev->key) {
            Prev->Left = newNode;
        }
        else {
            Prev->Right = newNode;
        }
    }
    return Root; // Возвращаем корень дерева
}

// Остальные функции остаются без изменений, но для полноты приведены некоторые исправления

int count(Tree* t, char letter) //Подсчет количества слов
{
    if (t)
    {
        count(t->Right, letter);
        if (t->text[0] == letter) // Проверяем первую букву слова
            c++;
        count(t->Left, letter);
    }
    return c;
}

Tree* delet(Tree* Root, int key)  //Удаление элемента по ключу
{	// Del, Prev_Del - удаляемый элемент и его предыдущий;
    // R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
    Tree* Del, * Prev_Del, * R, * Prev_R;
    Del = Root;
    Prev_Del = NULL;
    while (Del != NULL && Del->key != key)//поиск элемента и его родителя 
    {
        Prev_Del = Del;
        if (Del->key > key)
            Del = Del->Left;
        else
            Del = Del->Right;
    }
    if (Del == NULL)              // элемент не найден
    {
        puts("\nНет такого ключа");
        return Root;
    }
    if (Del->Right == NULL)     // поиск элемента R для замены
        R = Del->Left;
    else
        if (Del->Left == NULL)
            R = Del->Right;
        else
        {
            Prev_R = Del;      //поиск самого правого элемента в левом поддереве
            R = Del->Left;
            while (R->Right != NULL)
            {
                Prev_R = R;
                R = R->Right;
            }
            if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
                R->Right = Del->Right;
            else
            {
                R->Right = Del->Right;
                Prev_R->Right = R->Left;
                R->Left = Prev_R;
            }
        }
    if (Del == Root) Root = R;	//удаление корня и замена его на R
    else
        // поддерево R присоединяется к родителю удаляемого узла
        if (Del->key < Prev_Del->key)
            Prev_Del->Left = R;  //на левую ветвь 
        else
            Prev_Del->Right = R;	//на правую ветвь
    int tmp = Del->key;
    cout << "\nУдален элемент с ключом " << tmp << endl;
    delete Del;
    return Root;
}

Tree* search(Tree* n, int key)  //Поиск элемента по ключу 
{
    Tree* rc = n;
    if (rc != NULL)
    {
        if (key < (key, n->key))
            rc = search(n->Left, key);
        else
            if (key > (key, n->key))
                rc = search(n->Right, key);
    }
    else
        cout << "Нет такого элемента\n";
    return rc;
}
int countLeftNodes(Tree* node, Tree* parent, int& count) {
    if (node == nullptr) return count;
    if (parent != nullptr && parent->Left == node) {
        count++;
    }
    countLeftNodes(node->Left, node, count);
    countLeftNodes(node->Right, node, count);
    return count;
}

int countLeftChildren(Tree* root) {
    int count = 0;
    countLeftNodes(root, nullptr, count);
    return count;
}

int countLeafNodes(Tree* node) {
    if (node == NULL) return 0;
    if (node->Left == NULL && node->Right == NULL)
        return 1;
    return countLeafNodes(node->Left) + countLeafNodes(node->Right);
}

int countNodesWithKey(Tree* node, int k) {
    if (node == NULL) return 0;
    int currentCount = (node->key == k) ? 1 : 0;
    return currentCount
        + countNodesWithKey(node->Left, k)
        + countNodesWithKey(node->Right, k);
}

void printByLevels(Tree* root) {
    if (root == nullptr) {
        cout << "Дерево пустое\n";
        return;
    }
    queue<Tree*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            Tree* current = q.front();
            q.pop();
            cout << current->key << " (" << current->text << ") ";
            if (current->Left) q.push(current->Left);
            if (current->Right) q.push(current->Right);
        }
        cout << endl;
    }
}

int view(Tree* t, int level) //Вывод дерева 
{
    if (t)
    {
        view(t->Right, level + 1);	//вывод правого поддерева
        for (int i = 0; i < level; i++)
            cout << "   ";
        int tm = t->key;
        cout << tm << ' ';
        puts(t->text);
        view(t->Left, level + 1);	//вывод левого поддерева
        return 0;
    }
    return 1;
}

bool delAll(Tree* t) //Очистка дерева
{
    if (t != NULL)
    {
        delAll(t->Left);
        delAll(t->Right);
        delete t;
        return true;
    }
    return false;
}
