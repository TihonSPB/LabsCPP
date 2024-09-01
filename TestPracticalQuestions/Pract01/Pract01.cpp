#include <iostream>
#include <cstdlib> // Для использования malloc и free
#include <stdexcept> // Для использования std::out_of_range
#include <algorithm> // Для использования std::min

class A {
private:
    int* array;
    int arraySize;

public:
    // Конструктор по умолчанию
    A() : array(nullptr), arraySize(0) {}

    // Конструктор с параметром для задания размера массива
    A(int size) : arraySize(size) {
        if (size > 0) {
            array = static_cast<int*>(malloc(size * sizeof(int)));
            if (!array) {
                throw std::bad_alloc();
            }
            for (int i = 0; i < size; ++i) {
                array[i] = 0; // Инициализация элементов массива
            }
        }
        else {
            array = nullptr;
        }
    }

    // Конструктор копирования
    A(const A& other) : arraySize(other.arraySize) {
        if (arraySize > 0) {
            array = static_cast<int*>(malloc(arraySize * sizeof(int)));
            if (!array) {
                throw std::bad_alloc();
            }
            for (int i = 0; i < arraySize; ++i) {
                array[i] = other.array[i];
            }
        }
        else {
            array = nullptr;
        }
    }

    // Оператор присваивания
    A& operator=(const A& other) {
        if (this != &other) {
            free(array); // Освобождение текущего массива
            arraySize = other.arraySize;
            if (arraySize > 0) {
                array = static_cast<int*>(malloc(arraySize * sizeof(int)));
                if (!array) {
                    throw std::bad_alloc();
                }
                for (int i = 0; i < arraySize; ++i) {
                    array[i] = other.array[i];
                }
            }
            else {
                array = nullptr;
            }
        }
        return *this;
    }

    // Деструктор
    ~A() {
        free(array);
    }

    // Оператор индексации
    int& operator[](int index) {
        if (index < 0 || index >= arraySize) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    // Константный оператор индексации
    const int& operator[](int index) const {
        if (index < 0 || index >= arraySize) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    // Метод для получения размера массива
    int size() const {
        return arraySize;
    }
};

int main() {
    A a1;
    A a2(10); // 10 – размер массива
    A a3 = a2;
    a1 = a3;
    a2 = A(20);
    const A a4(5);
    for (int i = 0; i < std::min(a2.size(), a4.size()); i++) {
        std::cout << a4[i];
    }
    return 0;
}