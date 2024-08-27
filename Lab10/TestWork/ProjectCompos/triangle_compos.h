#pragma once
#include "dot.h"

using namespace std;

class Triangle
{
private:
    Dot pointA, pointB, pointC;

public:
    Triangle(Dot a, Dot b, Dot c);
    void sides();
    double perimeter();
    double area();
};