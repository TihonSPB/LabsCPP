// Передача массива в функцию 
//

#include <iostream>
using namespace std;

// Функция для сортировки массива методом выбора
void selectionSort(int* arr, int size) {
    int min, buf;
    for (int i = 0; i < size; i++) {
        min = i; // номер текущей ячейки, как ячейки с минимальным значением
        // в цикле найдем реальный номер ячейки с минимальным значением
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        // перестановка этого элемента, поменяв его местами с текущим
        if (i != min) {
            buf = arr[i];
            arr[i] = arr[min];
            arr[min] = buf;
        }
    }
}

// Функция для вывода массива на экран
void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << '\t';
    }
    cout << endl;
}

int main() {
    const int N = 10; // константа 10, задает размер массива

    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 }; // проинициализированный массив целых чисел размером N

    selectionSort(a, N); // сортировка массива

    printArray(a, N); // вывод отсортированного массива

    return 0;
}