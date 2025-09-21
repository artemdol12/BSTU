#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int TABLE_SIZE = 26;

class HashTable {
private:
    struct Entry {
        char key;
        int value;
        bool isActive;
    };

    Entry table[TABLE_SIZE];

    
    int hashFunction(char ch) {
        return tolower(ch) - 'a';
    }

    int probe(int index, int attempt) {
        return (index + attempt) % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = { '\0', 0, false };
        }
    }

    void insert(char ch) {
        ch = tolower(ch);
        if (!isalpha(ch)) return;

        int index = hashFunction(ch);
        int attempt = 0;

        while (attempt < TABLE_SIZE) {
            int current = probe(index, attempt);

            if (!table[current].isActive) {
                table[current].key = ch;
                table[current].value = 1;
                table[current].isActive = true;
                return;
            }
            else if (table[current].key == ch) {
                table[current].value++;
                return;
            }

            attempt++;
        }

        cerr << "Хеш-таблица переполнена!" << endl;
    }

    int search(char ch) {
        ch = tolower(ch);
        if (!isalpha(ch)) return 0;

        int index = hashFunction(ch);
        int attempt = 0;

        while (attempt < TABLE_SIZE) {
            int current = probe(index, attempt);

            if (!table[current].isActive) {
                break;
            }
            else if (table[current].key == ch) {
                return table[current].value;
            }

            attempt++;
        }

        return 0;
    }

    void printTable() {
        cout << "Хеш-таблица:\n";
        cout << "Индекс | Буква | Количество | Активна\n";
        cout << "------------------------------------\n";

        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "  " << i << "   |   ";
            if (table[i].isActive) {
                cout << table[i].key << "    |    " << table[i].value;
            }
            else {
                cout << " -    |     -";
            }
            cout << "    |   " << (table[i].isActive ? "да" : "нет") << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    HashTable ht;
    string input;

    cout << "Введите строку: ";
    getline(cin, input);

    for (char ch : input) {
        ht.insert(ch);
    }

    ht.printTable();

    char searchChar;
    cout << "\nВведите букву для поиска: ";
    cin >> searchChar;

    int count = ht.search(searchChar);
    if (count > 0) {
        cout << "Буква '" << searchChar << "' встречается " << count << " раз(а)\n";
    }
    else {
        cout << "Буква '" << searchChar << "' не найдена в строке\n";
    }

    return 0;
}