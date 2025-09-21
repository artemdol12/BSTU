#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <iomanip>
using namespace std;
using namespace std::chrono;

void generate_array(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10000;
    }
}

int create_array_b(int* a, int size_a, int* b) {
    if (size_a == 0) return 0;

    int max_index = 0;
    for (int i = 1; i < size_a; ++i) {
        if (a[i] > a[max_index]) {
            max_index = i;
        }
    }

    int size_b = 0;
    for (int i = max_index + 1; i < size_a; ++i) {
        if (i % 2 == 1) {
            b[size_b++] = a[i];
        }
    }

    return size_b;
}

void bubble_sort_desc(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void quick_sort_desc(int* arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[left + (right - left) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] > pivot) i++;
        while (arr[j] < pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quick_sort_desc(arr, left, j);
    quick_sort_desc(arr, i, right);
}

void selection_sort_desc(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int max_idx = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        swap(arr[i], arr[max_idx]);
    }
}

void insertion_sort_desc(int* arr, int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void shell_sort_desc(int* arr, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

double measure_sort_time(void (*sort_func)(int*, int), int* arr, int size) {
    auto start = high_resolution_clock::now();
    sort_func(arr, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000000.0;
}

double measure_quick_sort_time(int* arr, int size) {
    auto start = high_resolution_clock::now();
    quick_sort_desc(arr, 0, size - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000000.0;
}
void print_array_sample(const string& label, int* arr, int size) {
    cout << label << " (первые 30 элементов из " << size << "):" << endl;
    for (int j = 0; j < min(30, size); ++j) {
        cout << setw(6) << arr[j];
        if ((j + 1) % 10 == 0) cout << endl;
    }
    if (min(30, size) % 10 != 0) cout << endl;
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(nullptr));

    const int num_sizes = 5;
    int sizes[num_sizes] = { 1000, 2000, 3000, 4000, 5000 };
    double bubble_times[num_sizes] = { 0 };
    double quick_times[num_sizes] = { 0 };
    double selection_times[num_sizes] = { 0 };
    double insertion_times[num_sizes] = { 0 };
    double shell_times[num_sizes] = { 0 };

    for (int i = 0; i < num_sizes; ++i) {
        int size_a = sizes[i];
        int* a = new int[size_a];
        generate_array(a, size_a);

        cout << "==================================" << endl;
        cout << "РАЗМЕР МАССИВА A: " << size_a << endl;
        print_array_sample("Исходный массив A", a, size_a);

        int* b = new int[size_a];
        int size_b = create_array_b(a, size_a, b);

        if (size_b == 0) {
            cout << "Для размера " << size_a << " массив B пуст, пропускаем" << endl;
            delete[] a;
            delete[] b;
            continue;
        }

        print_array_sample("Сформированный массив B", b, size_b);

        // Создаем копии для каждой сортировки
        int* b_bubble = new int[size_b];
        int* b_quick = new int[size_b];
        int* b_selection = new int[size_b];
        int* b_insertion = new int[size_b];
        int* b_shell = new int[size_b];

        copy(b, b + size_b, b_bubble);
        copy(b, b + size_b, b_quick);
        copy(b, b + size_b, b_selection);
        copy(b, b + size_b, b_insertion);
        copy(b, b + size_b, b_shell);

        // Пузырьковая сортировка
        cout << "--- Пузырьковая сортировка ---" << endl;
        bubble_times[i] = measure_sort_time(bubble_sort_desc, b_bubble, size_b);
        print_array_sample("После сортировки", b_bubble, size_b);
        cout << "Время: " << bubble_times[i] << " сек" << endl << endl;

        // Быстрая сортировка
        cout << "--- Быстрая сортировка ---" << endl;
        quick_times[i] = measure_quick_sort_time(b_quick, size_b);
        print_array_sample("После сортировки", b_quick, size_b);
        cout << "Время: " << quick_times[i] << " сек" << endl << endl;

        // Сортировка выбором
        cout << "--- Сортировка выбором ---" << endl;
        selection_times[i] = measure_sort_time(selection_sort_desc, b_selection, size_b);
        print_array_sample("После сортировки", b_selection, size_b);
        cout << "Время: " << selection_times[i] << " сек" << endl << endl;

        // Сортировка вставками
        cout << "--- Сортировка вставками ---" << endl;
        insertion_times[i] = measure_sort_time(insertion_sort_desc, b_insertion, size_b);
        print_array_sample("После сортировки", b_insertion, size_b);
        cout << "Время: " << insertion_times[i] << " сек" << endl << endl;

        // Сортировка Шелла
        cout << "--- Сортировка Шелла ---" << endl;
        shell_times[i] = measure_sort_time(shell_sort_desc, b_shell, size_b);
        print_array_sample("После сортировки", b_shell, size_b);
        cout << "Время: " << shell_times[i] << " сек" << endl << endl;

        // Освобождение памяти
        delete[] a;
        delete[] b;
        delete[] b_bubble;
        delete[] b_quick;
        delete[] b_selection;
        delete[] b_insertion;
        delete[] b_shell;
    }

    // Вывод итоговых результатов
    cout << "\nИТОГОВЫЕ РЕЗУЛЬТАТЫ (время в секундах):\n";
    cout << "Размеры массивов: ";
    for (int size : sizes) cout << size << " ";
    cout << "\n\n";

    cout << "Алгоритм сортировки\t\t";
    for (int size : sizes) cout << size << "\t";
    cout << "\n";

    cout << "Пузырьковая\t\t\t";
    for (double time : bubble_times) cout << time << "\t";
    cout << "\n";

    cout << "Быстрая\t\t\t";
    for (double time : quick_times) cout << time << "\t";
    cout << "\n";

    cout << "Выбором\t\t\t\t";
    for (double time : selection_times) cout << time << "\t";
    cout << "\n";

    cout << "Вставками\t\t\t";
    for (double time : insertion_times) cout << time << "\t";
    cout << "\n";

    cout << "Шелла\t\t\t\t";
    for (double time : shell_times) cout << time << "\t";
    cout << "\n";

    return 0;
}