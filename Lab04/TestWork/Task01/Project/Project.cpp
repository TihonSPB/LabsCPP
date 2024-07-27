// Вычисление корней квадратного уравнения
//

#include <iostream>
#include <cmath>

using namespace std;

int Myroot(double, double, double, double&, double&);

int main(){

    system("chcp 1251");

    double a, b, c;
    double x1, x2;

    cout << "Введите коэффициенты a, b, c для уравнения ax^2 + bx + c = 0. " << endl;
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите c: ";
    cin >> c;

    int result = Myroot(a, b, c, x1, x2);

    if (result == 1) {
        cout << "Корни уравнения x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else if (result == 0) {
        cout << "Корень уравнения один x1 = x2 = " << x1 << endl;
    }
    else {
        cout << "Корней уравнения нет" << endl;
    }

    return 0;
}

int Myroot(double a, double b, double c, double& x1, double& x2) {
    double diskr = b * b - 4 * a * c; // Вычисление дискриминанта

    if (diskr > 0) {
        x1 = (-b + sqrt(diskr)) / (2 * a);
        x2 = (-b - sqrt(diskr)) / (2 * a);
        return 1; // Два различных корня
    }
    else if (diskr == 0) {
        x1 = x2 = -b / (2 * a);
        return 0; // Один корень (два совпадающих)
    }
    else {
        return -1; // Корней нет
    }
}

