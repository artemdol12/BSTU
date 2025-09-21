#include <iostream>

using namespace std;
// Базовый класс
class Spider {
public:
    // Конструктор по умолчанию
    Spider() {
        cout << "Паук создан\n";
    }

    // Конструктор копирования
    Spider(const Spider& other) {
        cout << "Паук скопирован\n";
    }

    // Виртуальный деструктор
    virtual ~Spider() {
        cout << "Паук уничтожен\n";
    }

    // Виртуальный метод
    virtual void makeWeb() const {
        cout << "Паук плетет паутину\n";
    }
};

// Производный класс
class Tarantula : public Spider {
public:
    // Конструктор
    Tarantula() {
        cout << "Тарантул создан\n";
    }

    // Конструктор копирования
    Tarantula(const Tarantula& other) : Spider(other) {
        cout << "Тарантул скопирован\n";
    }

    // Деструктор
    ~Tarantula() override {
        cout << "Тарантул уничтожен\n";
    }

    // Переопределенный виртуальный метод
    void makeWeb() const override {
        cout << "Тарантул плетет прочную паутину\n";
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    cout << "=== Создание тарантула через указатель ===\n";
    Spider* spider = new Tarantula();

    cout << "\n=== Вызов метода ===\n";
    spider->makeWeb();

    cout << "\n=== Создание оригинального тарантула ===\n";
    Tarantula original;

    cout << "\n=== Копирование тарантула ===\n";
    Tarantula copy = original;

    cout << "\n=== Удаление через указатель ===\n";
    delete spider;

    cout << "\n=== Завершение программы (автоматическое удаление) ===\n";
    return 0;
}