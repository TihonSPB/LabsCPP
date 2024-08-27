#include "triangle_compos.h"
#include <iostream>
#include <string>

Triangle::Triangle(Dot a, Dot b, Dot c) : pointA(a), pointB(b), pointC(c)
{}

void Triangle::sides()
{
    double sideAB = pointA.distanceTo(pointB);
    double sideBC = pointB.distanceTo(pointC);
    double sideCA = pointC.distanceTo(pointA);

    cout << to_string(sideAB) + ", " + to_string(sideBC) + ", " + to_string(sideCA) + "\n";
}

double Triangle::perimeter()
{
    double side1 = pointA.distanceTo(pointB);
    double side2 = pointB.distanceTo(pointC);
    double side3 = pointC.distanceTo(pointA);

    return side1 + side2 + side3;
}

double Triangle::area()
{
    double side1 = pointA.distanceTo(pointB);
    double side2 = pointB.distanceTo(pointC);
    double side3 = pointC.distanceTo(pointA);

    double s = (side1 + side2 + side3) / 2;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}