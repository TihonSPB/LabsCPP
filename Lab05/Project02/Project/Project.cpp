﻿// Сортировка массива 
//

#include <iostream>
using namespace std;

int main()
{
    const int N = 10;//константа 10, задает размер массива. 

    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 }; //проинициализированный массив целых чисел размером N.

    int min = 0; // для записи минимального значения 
    int buf = 0; // для обмена значениями

    for (int i = 0; i < N; i++)
    {
        min = i; // номер текущей ячейки, как ячейки с минимальным значением  
        // в цикле найдем реальный номер ячейки с минимальным значением  
        for (int j = i + 1; j < N; j++) 
        min = (a[j] < a[min]) ? j : min;
        // перестановка этого элемента, поменяв его местами с текущим  
        if (i != min) 
        {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }

    //вывод отсортированного массива
    for (int i : a)
        cout << i << '\t';
}
