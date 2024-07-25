// Расчет площади многоугольника

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    system("chcp 1251");

    double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;

    // Запрос координат вершин пятиугольника
    cout << "Введите координаты вершин пятиугольника (x1 y1 x2 y2 x3 y3 x4 y4 x5 y5): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5;

    // Вычисление площади пятиугольника по формуле Гаусса
    double area = 0.5 * fabs(
        x1 * y2 + x2 * y3 + x3 * y4 + x4 * y5 + x5 * y1 -
        y1 * x2 - y2 * x3 - y3 * x4 - y4 * x5 - y5 * x1
    );

    // Вывод результата
    cout << "Площадь пятиугольника: " << area << endl;

    return 0;
}