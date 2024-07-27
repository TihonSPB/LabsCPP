// Передача массива в функцию 
//

#include <iostream>
#include <limits>
using namespace std;

// Функция для заполнения массива с клавиатуры
void fillArray(int* mas, int n) {
    for (int i = 0; i < n; i++) {
        cout << "mas[" << i << "]=";
        cin >> mas[i];
    }
}

// Функция для вычисления суммы всех элементов массива
int sumAllElements(const int* mas, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += mas[i];
    }
    return s;
}

// Функция для вычисления суммы отрицательных элементов
int sumNegativeElements(const int* mas, int n) {
    int sumNegative = 0;
    for (int i = 0; i < n; i++) {
        if (mas[i] < 0)
            sumNegative += mas[i];
    }
    return sumNegative;
}

// Функция для вычисления суммы положительных элементов
int sumPositiveElements(const int* mas, int n) {
    int sumPositive = 0;
    for (int i = 0; i < n; i++) {
        if (mas[i] > 0)
            sumPositive += mas[i];
    }
    return sumPositive;
}

// Функция для вычисления суммы элементов с нечетными индексами
int sumOddIndexesElements(const int* mas, int n) {
    int sumOddIndexes = 0;
    for (int i = 1; i < n; i += 2) {
        sumOddIndexes += mas[i];
    }
    return sumOddIndexes;
}

// Функция для вычисления суммы элементов с четными индексами
int sumEvenIndexesElements(const int* mas, int n) {
    int sumEvenIndexes = 0;
    for (int i = 0; i < n; i += 2) {
        sumEvenIndexes += mas[i];
    }
    return sumEvenIndexes;
}

// Функция для нахождения максимального и минимального элементов массива
void findMinMax(const int* mas, int n, int& maxElement, int& minElement, int& maxIndex, int& minIndex) {
    maxElement = numeric_limits<int>::min();
    minElement = numeric_limits<int>::max();
    maxIndex = -1;
    minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (mas[i] > maxElement) {
            maxElement = mas[i];
            maxIndex = i;
        }
        if (mas[i] < minElement) {
            minElement = mas[i];
            minIndex = i;
        }
    }
}

// Функция для вычисления произведения элементов массива, расположенных между максимальным и минимальным элементами
long long productBetweenMinMax(const int* mas, int start, int end) {
    long long productBetween = 1;
    for (int i = start + 1; i < end; i++) {
        productBetween *= mas[i];
    }
    return productBetween;
}

int main() {
    system("chcp 1251");

    const int n = 10; // объявляем константу, равную 10, она будет задавать размер массива.

    int mas[n]; // массив целых чисел размером n

    fillArray(mas, n); // заполнение массива с клавиатуры

    int s = sumAllElements(mas, n); // сумма всех элементов массива
    int sumNegative = sumNegativeElements(mas, n); // сумма отрицательных элементов
    int sumPositive = sumPositiveElements(mas, n); // сумма положительных элементов
    int sumOddIndexes = sumOddIndexesElements(mas, n); // сумма элементов с нечетными индексами
    int sumEvenIndexes = sumEvenIndexesElements(mas, n); // сумма элементов с четными индексами

    int maxElement, minElement, maxIndex, minIndex;
    findMinMax(mas, n, maxElement, minElement, maxIndex, minIndex); // максимальный и минимальный элементы массива

    long long productBetween = productBetweenMinMax(mas, min(maxIndex, minIndex), max(maxIndex, minIndex)); // произведение элементов между максимальным и минимальным элементами

    // вывод
    cout << "Сумма всех элементов массива = " << s << endl;
    cout << "Сумма отрицательных элементов = " << sumNegative << endl;
    cout << "Сумма положительных элементов = " << sumPositive << endl;
    cout << "Сумма элементов с нечетными индексами = " << sumOddIndexes << endl;
    cout << "Сумма элементов с четными индексами = " << sumEvenIndexes << endl;
    cout << "Максимальный элемент = " << maxElement << " с индексом " << maxIndex << endl;
    cout << "Минимальный элемент = " << minElement << " с индексом " << minIndex << endl;
    cout << "Произведение элементов между максимальным и минимальным = " << productBetween << endl;

    return 0;
}