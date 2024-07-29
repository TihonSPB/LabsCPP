// Использование массива структур
//

#include <iostream>
#include <windows.h> 
using namespace std;

struct Distance //структура Distance
{
    int feet;
    double inches;

    void ShowDist()
    {
        cout << feet << "\'-" << inches << "\"\n";
    }
};

//Distance AddDist(Distance d1, Distance d2) // функция сложения двух переменных типа Distance
Distance AddDist(const Distance& d1, const Distance& d2) // копия передаваемого объекта не создается. константные ссылки, которые запрещают изменение объекта внутри функции
{
    Distance d;
    d.feet = d1.feet + d2.feet;
    d.inches = d1.inches + d2.inches;
    if (d.inches >= 12.0)
    {
        d.inches -= 12.0;
        d.feet++;
    }
    return d;
}

Distance InputDist() // функция для ввода значений футов и дюймов
{
    Distance d;
    cout << "\nВведите число футов: ";
    cin >> d.feet;
    cout << "Введите число дюймов: ";
    cin >> d.inches;
    return d;
}


void ShowDist(Distance d) // вывод информации о переменной структуры
{
    cout << d.feet << "\'-" << d.inches << "\"\n";
}

int main()
{
    system("chcp 1251");

    Distance d1 = InputDist();
    Distance d2 = { 1, 6.25 };

    Distance d3 = AddDist(d1, d2);

    /*
    ShowDist(d1);
    ShowDist(d2);
    ShowDist(d3);
    */

    d1.ShowDist();
    d2.ShowDist();
    d3.ShowDist();

    int n;
    cout << "Введите размер массива расстояний ";
    cin >> n;

    Distance* masDist = new Distance[n]; // массив переменных типа Distance

    for (int i = 0; i < n; i++) // цикл вызова функции ввода значений футов и дюймов для каждого элемента массива
    {
        masDist[i] = InputDist();
    }

    for (int i = 0; i < n; i++) // цикл вызова функции вывода значений на экран для каждого элемента массива 
    {
        ShowDist(masDist[i]);
    }

    Distance sum = { 0, 0 };
    for (int i = 0; i < n; i++) // цикл вызова функции сложения всех переменных массива
    {
        sum = AddDist(sum, masDist[i]);
    }

    cout << "Сумма расстояний = ";  
    ShowDist(sum);

    delete[] masDist; // оператор высвобождения памяти, занимаемой массивом

    return 0;
}