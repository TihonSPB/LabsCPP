// Реализация класса Triangle
// агрегация (часть и целое могут существовать по-отдельности)

#include <iostream>
#include "dot.h"
#include "triangle_aggreg.h"

int main()
{
    system("chcp 1251");

    // Координаты точек
    Dot* pointA = new Dot(0, 0);
    Dot* pointB = new Dot(3, 2);
    Dot* pointC = new Dot(2, 3);

    Triangle Triangle2(pointA, pointB, pointC);
    
    cout << "Длины сторон(A-B, B-C, C-A): "; 
    Triangle2.sides();
    cout << "Периметр: " << Triangle2.perimeter() << endl;
    cout << "Площадь: " << Triangle2.area() << endl;

    delete pointA;
    delete pointB;
    delete pointC;
    
    return 0;
}