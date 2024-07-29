// Применение структур и кортежей 
// Реализация структуры Distance 

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

Distance AddDist(Distance d1, Distance d2) // ункция сложения двух переменных типа Distance
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

/* Перенесено в структуру
void ShowDist(Distance d) // вывод информации о переменной структуры
{
    cout << d.feet << "\'-" << d.inches << "\"\n";
}
*/

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

    return 0;
}