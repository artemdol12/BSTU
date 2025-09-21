#include <iostream>
#include "List.h"

// Функция для вывода информации о студенте
void PrintStudent(void* data) {
    std::cout << *(std::string*)data << std::endl;
}

void ShowMenu() {
    std::cout << "\n=== Меню управления списком ===\n";
    std::cout << "1. Добавить элемент в начало списка\n";
    std::cout << "2. Добавить элемент в конец списка\n";
    std::cout << "3. Удалить элемент\n";
    std::cout << "4. Найти элемент\n";
    std::cout << "5. Вывести список\n";
    std::cout << "6. Подсчитать количество элементов\n";
    std::cout << "7. Удалить весь список\n";
    std::cout << "0. Выход\n";
    std::cout << "Выберите действие: ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    Object list = Create();
    int choice;
    std::string input;

    do {
        ShowMenu();
        std::cin >> choice;
        std::cin.ignore(); // Очистка буфера ввода

        switch (choice) {
            case 1: {
                std::cout << "Введите информацию о студенте: ";
                std::getline(std::cin, input);
                std::string* data = new std::string(input);
                list.Insert(data);
                break;
            }
            case 2: {
                std::cout << "Введите информацию о студенте: ";
                std::getline(std::cin, input);
                std::string* data = new std::string(input);
                list.InsertEnd(data);
                break;
            }
            case 3: {
                std::cout << "Введите информацию о студенте для удаления: ";
                std::getline(std::cin, input);
                std::string* data = new std::string(input);
                if (list.Delete(data)) {
                    std::cout << "Элемент удален\n";
                } else {
                    std::cout << "Элемент не найден\n";
                }
                delete data;
                break;
            }
            case 4: {
                std::cout << "Введите информацию о студенте для поиска: ";
                std::getline(std::cin, input);
                std::string* data = new std::string(input);
                Element* found = list.Search(data);
                if (found) {
                    std::cout << "Элемент найден\n";
                } else {
                    std::cout << "Элемент не найден\n";
                }
                delete data;
                break;
            }
            case 5: {
                std::cout << "Содержимое списка:\n";
                list.PrintList(PrintStudent);
                break;
            }
            case 6: {
                std::cout << "Количество элементов в списке: " << list.CountList() << std::endl;
                break;
            }
            case 7: {
                if (list.DeleteList()) {
                    std::cout << "Список успешно удален\n";
                }
                break;
            }
            case 0:
                std::cout << "Выход из программы\n";
                break;
            default:
                std::cout << "Неверный выбор\n";
        }
    } while (choice != 0);

    // Очистка памяти перед выходом
    list.DeleteList();
    return 0;
} 