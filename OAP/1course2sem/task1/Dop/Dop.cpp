#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <map>
#include <numeric>
#include <cstring>
using namespace std;

const int NUM_SUBJECTS = 5;
const int MAX_GROUP_LEN = 10;

struct Student {
    char last_name[50];
    char first_name[50];
    char patronymic[50];
    int birth_year;
    int course;
    char group[MAX_GROUP_LEN];
    int marks[NUM_SUBJECTS];
    Student* next;
    Student* prev;
};

// Прототипы функций
int menu();
void insert(Student* s, Student** head, Student** tail);
Student* createStudent();
void printStudent(Student* s);
void printList(Student** head);
void deleteStudent(const char* last_name, Student** head, Student** tail);
void saveToFile(Student** head);
void loadFromFile(Student** head, Student** tail);
void split(Student* head, Student** a, Student** b);
Student* merge(Student* a, Student* b, bool (*cmp)(Student*, Student*));
void mergeSort(Student** head, bool (*cmp)(Student*, Student*));
bool compareStudents(Student* a, Student* b);
void sortStudents(Student** head, Student** tail);
void groupAverages(Student** head);
void ageAnalysis(Student** head);
void bestStudents(Student** head);
void findStudent(const char* last_name, Student** head);

//-----------------------------------------------------------
int menu() {
    system("cls");
    int c;
    cout << "\n1. Добавить студента\n"
        << "2. Удалить студента\n"
        << "3. Вывести список\n"
        << "4. Поиск студента\n"
        << "5. Сохранить в файл\n"
        << "6. Загрузить из файла\n"
        << "7. Сортировка студентов\n"
        << "8. Средний балл групп\n"
        << "9. Старший/младший студент\n"
        << "10. Лучшие студенты групп\n"
        << "11. Выход\n\n";

    do {
        cout << "Ваш выбор: ";
        cin >> c;
        cin.ignore();
    } while (c < 1 || c > 11);
    return c;
}

//-----------------------------------------------------------
void insert(Student* s, Student** head, Student** tail) {
    if (!*tail) {
        s->next = s->prev = nullptr;
        *head = *tail = s;
    }
    else {
        s->prev = *tail;
        (*tail)->next = s;
        *tail = s;
        s->next = nullptr;
    }
}

//-----------------------------------------------------------
Student* createStudent() {
    Student* s = new Student();

    cout << "Фамилия: ";
    cin.getline(s->last_name, 50);

    cout << "Имя: ";
    cin.getline(s->first_name, 50);

    cout << "Отчество: ";
    cin.getline(s->patronymic, 50);

    cout << "Год рождения: ";
    cin >> s->birth_year;

    cout << "Курс: ";
    cin >> s->course;

    cin.ignore();
    cout << "Группа: ";
    cin.getline(s->group, MAX_GROUP_LEN);

    cout << "Оценки по 5 предметам (через пробел): ";
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        cin >> s->marks[i];
    }
    cin.ignore();

    s->next = s->prev = nullptr;
    return s;
}

//-----------------------------------------------------------
void printStudent(Student* s) {
    cout << s->last_name << " "
        << s->first_name << " "
        << s->patronymic << ", "
        << "Курс: " << s->course
        << ", Группа: " << s->group
        << ", Средний балл: "
        << (accumulate(s->marks, s->marks + NUM_SUBJECTS, 0.0) / NUM_SUBJECTS)
        << endl;
}

//-----------------------------------------------------------
void printList(Student** head) {
    Student* t = *head;
    while (t) {
        printStudent(t);
        t = t->next;
    }
    system("pause");
}

//-----------------------------------------------------------
void deleteStudent(const char* last_name, Student** head, Student** tail) {
    Student* t = *head;
    while (t) {
        if (strcmp(t->last_name, last_name) == 0) {
            if (t->prev) t->prev->next = t->next;
            if (t->next) t->next->prev = t->prev;
            if (t == *head) *head = t->next;
            if (t == *tail) *tail = t->prev;
            delete t;
            cout << "Удалено!\n";
            system("pause");
            return;
        }
        t = t->next;
    }
    cout << "Не найдено!\n";
    system("pause");
}

//-----------------------------------------------------------
void saveToFile(Student** head) {
    ofstream fout("students.dat", ios::binary);
    Student* t = *head;
    while (t) {
        fout.write(reinterpret_cast<char*>(t), sizeof(Student));
        t = t->next;
    }
    fout.close();
    cout << "Сохранено!\n";
    system("pause");
}

//-----------------------------------------------------------
void loadFromFile(Student** head, Student** tail) {
    ifstream fin("students.dat", ios::binary);
    if (!fin) {
        cout << "Файл не найден!\n";
        system("pause");
        return;
    }

    while (*head) {
        Student* temp = (*head)->next;
        delete* head;
        *head = temp;
    }
    *head = *tail = nullptr;

    Student temp;
    while (fin.read(reinterpret_cast<char*>(&temp), sizeof(Student))) {
        Student* newNode = new Student();
        strcpy_s(newNode->last_name, temp.last_name);
        strcpy_s(newNode->first_name, temp.first_name);
        strcpy_s(newNode->patronymic, temp.patronymic);
        newNode->birth_year = temp.birth_year;
        newNode->course = temp.course;
        strcpy_s(newNode->group, temp.group);
        copy(temp.marks, temp.marks + NUM_SUBJECTS, newNode->marks);
        newNode->next = newNode->prev = nullptr;
        insert(newNode, head, tail);
    }
    fin.close();
    cout << "Загружено!\n";
    system("pause");
}

//-----------------------------------------------------------
void split(Student* head, Student** a, Student** b) {
    Student* fast = head->next;
    Student* slow = head;

    while (fast) {
        fast = fast->next;
        if (fast) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    *a = head;
    *b = slow->next;
    if (*b) (*b)->prev = nullptr;
    slow->next = nullptr;
}

//-----------------------------------------------------------
Student* merge(Student* a, Student* b, bool (*cmp)(Student*, Student*)) {
    if (!a) return b;
    if (!b) return a;

    if (cmp(a, b)) {
        a->next = merge(a->next, b, cmp);
        a->next->prev = a;
        a->prev = nullptr;
        return a;
    }
    else {
        b->next = merge(a, b->next, cmp);
        b->next->prev = b;
        b->prev = nullptr;
        return b;
    }
}

//-----------------------------------------------------------
void mergeSort(Student** head, bool (*cmp)(Student*, Student*)) {
    if (!*head || !(*head)->next) return;

    Student* a;
    Student* b;
    split(*head, &a, &b);

    mergeSort(&a, cmp);
    mergeSort(&b, cmp);

    *head = merge(a, b, cmp);
}

//-----------------------------------------------------------
bool compareStudents(Student* a, Student* b) {
    if (a->course != b->course)
        return a->course < b->course;
    return strcmp(a->last_name, b->last_name) < 0;
}

//-----------------------------------------------------------
void sortStudents(Student** head, Student** tail) {
    if (!*head || !(*head)->next) return;

    mergeSort(head, compareStudents);

    *tail = *head;
    while (*tail && (*tail)->next)
        *tail = (*tail)->next;

    Student* current = *head;
    Student* prev = nullptr;
    while (current) {
        current->prev = prev;
        prev = current;
        current = current->next;
    }
}

//-----------------------------------------------------------
void groupAverages(Student** head) {
    struct GroupData {
        double sums[NUM_SUBJECTS] = { 0 };
        int count = 0;
    };

    map<string, GroupData> groups;

    Student* t = *head;
    while (t) {
        GroupData& gd = groups[t->group];
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            gd.sums[i] += t->marks[i];
        }
        gd.count++;
        t = t->next;
    }

    for (auto& [group, data] : groups) {
        cout << "\nГруппа " << group << ":\n";
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            cout << "Предмет " << i + 1 << ": "
                << data.sums[i] / data.count << endl;
        }
    }
    system("pause");
}

//-----------------------------------------------------------
void ageAnalysis(Student** head) {
    if (!*head) {
        cout << "Список пуст!\n";
        system("pause");
        return;
    }

    Student* oldest = *head;
    Student* youngest = *head;
    Student* t = *head;

    while (t) {
        if (t->birth_year < oldest->birth_year) oldest = t;
        if (t->birth_year > youngest->birth_year) youngest = t;
        t = t->next;
    }

    cout << "Самый старший студент:\n";
    printStudent(oldest);
    cout << "\nСамый младший студент:\n";
    printStudent(youngest);
    system("pause");
}

//-----------------------------------------------------------
void bestStudents(Student** head) {
    map<string, Student*> bestInGroup;

    Student* t = *head;
    while (t) {
        double currentAvg = accumulate(t->marks, t->marks + NUM_SUBJECTS, 0.0) / NUM_SUBJECTS;

        if (bestInGroup.find(t->group) == bestInGroup.end() ||
            currentAvg > accumulate(bestInGroup[t->group]->marks,
                bestInGroup[t->group]->marks + NUM_SUBJECTS, 0.0) / NUM_SUBJECTS) {
            bestInGroup[t->group] = t;
        }
        t = t->next;
    }

    cout << "Лучшие студенты по группам:\n";
    for (auto& [group, student] : bestInGroup) {
        cout << "\nГруппа " << group << ":\n";
        printStudent(student);
    }
    system("pause");
}

//-----------------------------------------------------------
void findStudent(const char* last_name, Student** head) {
    Student* t = *head;
    bool found = false;

    while (t) {
        if (strcmp(t->last_name, last_name) == 0) {
            printStudent(t);
            found = true;
        }
        t = t->next;
    }

    if (!found) {
        cout << "Студент не найден!\n";
    }
    system("pause");
}

//-----------------------------------------------------------
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(0, "Rus");

    Student* head = nullptr;
    Student* tail = nullptr;

    while (true) {
        switch (menu()) {
        case 1: insert(createStudent(), &head, &tail); break;
        case 2: {
            char name[50];
            cout << "Введите фамилию: ";
            cin.getline(name, 50);
            deleteStudent(name, &head, &tail);
            break;
        }
        case 3: printList(&head); break;
        case 4: {
            char name[50];
            cout << "Введите фамилию для поиска: ";
            cin.getline(name, 50);
            findStudent(name, &head);
            break;
        }
        case 5: saveToFile(&head); break;
        case 6: loadFromFile(&head, &tail); break;
        case 7: sortStudents(&head, &tail); break;
        case 8: groupAverages(&head); break;
        case 9: ageAnalysis(&head); break;
        case 10: bestStudents(&head); break;
        case 11: exit(0);
        default: break;
        }
    }
    return 0;
}