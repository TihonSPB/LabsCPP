// Обработка данных массива 
//

#include <iostream>
using namespace std;

int main()
{
    system("chcp 1251");

    const int n = 10; //объявляем константу, равную 10, она будет задавать размер массива. 

    int mas[n]; //массив целых чисел размером n

    //заполнение массива с клавиатуры
    for (int i = 0; i < n; i++) 
    {
        cout << "mas[" << i << "]=";
        cin >> mas[i];
    }

    //сумма всех элементов массива
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += mas[i];
    }

    //расчет суммы отрицательных элементов
    int sumNegative = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] < 0)
            sumNegative += mas[i];
    }

    //расчет суммы положительных элементов
    int sumPositive = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] > 0)
            sumPositive += mas[i];
    }

    //расчет суммы элементов с нечетными индексами
    int sumOddIndexes = 0;
    for (int i = 1; i < n; i += 2)
    {
        sumOddIndexes += mas[i];
    }

    //расчет суммы элементов с четными индексами
    int sumEvenIndexes = 0;
    for (int i = 0; i < n; i += 2)
    {
        sumEvenIndexes += mas[i];
    }

    //максимальный и минимальный элементы массива
    int maxElement = numeric_limits<int>::min();
    int minElement = numeric_limits<int>::max();
    int maxIndex = -1, minIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] > maxElement)
        {
            maxElement = mas[i];
            maxIndex = i;
        }
        if (mas[i] < minElement)
        {
            minElement = mas[i];
            minIndex = i;
        }
    }

    //произведение элементов массива, расположенных между максимальным и минимальным элементами
    long long productBetween = 1;
    int start = min(maxIndex, minIndex);
    int end = max(maxIndex, minIndex);
    for (int i = start + 1; i < end; i++)
    {
        productBetween *= mas[i];
    }

    //вывод 
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