#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <chrono>  
#include <iomanip> 

using namespace std;

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int partitionIndex = i + 1;

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main() {
    setlocale(LC_ALL, "rus");

    int N;
    cout << "Введите количество чисел для генерации массива: ";
    cin >> N;

    if (N < 1) {
        cout << "Количество чисел должно быть положительным." << endl;
        return 0;
    }

    srand(static_cast<unsigned int>(time(0)));

    int* A = new int[N]; 
    int* B = new int[N];
    int* C = new int[N];
    int* D = new int[N];
    int* E = new int[N];

    for (int i = 0; i < N; ++i) {
        A[i] = rand() % 20;
    }

    for (int i = 0; i < N; ++i) {
        B[i] = A[i];
        C[i] = A[i];
        D[i] = A[i];
        E[i] = A[i];
    }

    cout << "Сгенерированный массив A: ";
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(B, N);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Отсортированный массив B (пузырьковая сортировка): ";
    for (int i = 0; i < N; ++i) {
        cout << B[i] << " ";
    }
    cout << endl;
    cout << "Затраченное время: " << fixed << setprecision(8) << elapsed.count() << " секунд" << endl;

    start = chrono::high_resolution_clock::now();
    insertionSort(C, N);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Отсортированный массив C (сортировка вставками): ";
    for (int i = 0; i < N; ++i) {
        cout << C[i] << " ";
    }
    cout << endl;
    cout << "Затраченное время: " << fixed << setprecision(8) << elapsed.count() << " секунд" << endl;

    start = chrono::high_resolution_clock::now();
    selectionSort(D, N);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Отсортированный массив D (сортировка выбором): ";
    for (int i = 0; i < N; ++i) {
        cout << D[i] << " ";
    }
    cout << endl;
    cout << "Затраченное время: " << fixed << setprecision(8) << elapsed.count() << " секунд" << endl;

    start = chrono::high_resolution_clock::now();
    quickSort(E, 0, N - 1);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Отсортированный массив E (быстрая сортировка): ";
    for (int i = 0; i < N; ++i) {
        cout << E[i] << " ";
    }
    cout << endl;
    cout << "Затраченное время: " << fixed << setprecision(8) << elapsed.count() << " секунд" << endl;

    delete[] A;
    delete[] B;
    delete[] C;
    delete[] D;
    delete[] E;

    return 0;
}