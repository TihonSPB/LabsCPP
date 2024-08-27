// Безопасная реализация класса Triangle 
//

#include <iostream>
#include<cmath>
using namespace std;

class TriangleError : public exception {
public:
    const char* what() const noexcept override {
        return "Невозможно создать треугольник.";
    }
};

class Triangle
{
private:
    double sideA;
    double sideB;
    double sideC;
public:    
    Triangle(double a, double b, double c) {
        if (a + b <= c || b + c <= a || a + c <= b) 
            throw TriangleError();        
        sideA = a;
        sideB = b;
        sideC = c;
    }
    double get_sideA() const {
        return sideA;
    }  
    double get_sideB() const {
        return sideB;
    }
    double get_sideC() const {
        return sideC;
    }
    double get_square() const {
        double p = (sideA + sideB + sideC) / 2;
        return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
    }
};

int main()
{
    system("chcp 1251"); 

    double a;
    double b;
    double c;

    cout << "Введите стороны треугольника a, b, c: ";
    cin >> a >> b >> c;  

    try {
        Triangle t(a, b, c);
        cout << "a\tb\tc\t" << "| " << "Площадь треугольника\n";
        cout << t.get_sideA() << "\t" << t.get_sideB() << "\t" << t.get_sideC() << "\t" << "| " << t.get_square() << endl;
    }
    catch (const TriangleError& e) {
        cout << e.what() << endl;
        return 1;
    }
     
    return 0;
}