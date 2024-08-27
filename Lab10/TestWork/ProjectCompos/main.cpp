// Реализация класса Triangle
// композиция (целое отвечает за жизненный цикл части)

#include <iostream>
#include "dot.h"
#include "triangle_compos.h"

int main()
{
    system("chcp 1251");

    // Координаты точек
    Dot pointA(0, 0);
    Dot pointB(3, 2);
    Dot pointC(2, 3);

    Triangle Triangle1(pointA, pointB, pointC);
    
    cout << "Длины сторон(A-B, B-C, C-A): "; 
    Triangle1.sides();
    cout << "Периметр: " << Triangle1.perimeter() << endl;
    cout << "Площадь: " << Triangle1.area() << endl;

    return 0;
}