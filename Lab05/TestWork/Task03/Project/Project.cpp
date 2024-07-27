// Реализация алгоритмов поиска методом транспозиции 
//

#include <iostream>

using namespace std;

// Функция поиска элемента с использованием алгоритма транспозиции
int findWithTransposition(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            if (i > 0) {
                // Обмен элементов местами
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                return i - 1; // Возвращаем индекс новой позиции элемента
            }
            return i; // Возвращаем индекс, если элемент уже на первой позиции
        }
    }
    return -1; // Возвращаем -1, если элемент не найден
}

int main() {
    system("chcp 1251");

    int arr[] = { 8, 2, 7, 4, 5, 9, 1, 6, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 9;

    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int index = findWithTransposition(arr, size, key);

    if (index != -1) {
        cout << "Элемент " << key << " найден по индексу " << index << " после транспозиции." << endl;
    }
    else {
        cout << "Элемент " << key << " не найден." << endl;
    }

    cout << "Измененный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}