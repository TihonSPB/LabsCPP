// Шаблонная функция обработки массива

#include <iostream>

// Шаблон функции для вычисления среднего арифметического
template<class T>
T average(T array[], int size) {
    if (size == 0) return T(); // Возвращаем значение по умолчанию для типа T, если массив пуст

    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum / size;
}

int main() {

    system("chcp 1251");

    // Проверка с массивом типа int
    int intArray[] = { 1, 2, 3, 4, 5 };
    int arrIntSize = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Cреднее арифметическое intArray: " << average(intArray, arrIntSize) << std::endl;

    // Проверка с массивом типа long
    long longArray[] = { 10L, 20L, 30L, 40L, 50L };
    int arrLongSize = sizeof(longArray) / sizeof(longArray[0]);
    std::cout << "Cреднее арифметическое longArray: " << average(longArray, arrLongSize) << std::endl;

    // Проверка с массивом типа double
    double doubleArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    int arrDoubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    std::cout << "Cреднее арифметическое doubleArray: " << average(doubleArray, arrDoubleSize) << std::endl;

    // Проверка с массивом типа char
    char charArray[] = { 'a', 'b', 'c', 'd', 'e' };
    int arrCharSize = sizeof(charArray) / sizeof(charArray[0]);
    std::cout << "Cреднее арифметическое charArray: " << average(charArray, arrCharSize) << std::endl;

    return 0;
}
