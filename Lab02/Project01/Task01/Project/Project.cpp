//Реализация операторов выбора
//Определение принадлежности точки заданной фигуре

#include <iostream>

using namespace std;

int main()
{
    system("chcp 1251");

    double x, y;

    // Запрос координат
    cout << "Введите x y: ";
    cin >> x >> y;

    if (x * x + y * y < 9 && y > 0)
        cout << "внутри";
    else if (x * x + y * y > 9 || y < 0)
        cout << "снаружи";
    else
        cout << "на границе";
}

