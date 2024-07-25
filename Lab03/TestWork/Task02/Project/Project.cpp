// Применение итерации реализации функции

#include <iostream>
#include <cmath>

using namespace std;

double cubicRootUsingPow(double a) {
    return pow(a, 1.0 / 3.0);
}

double cubicRootUsingIteration(double a, double epsilon = 1e-10) {
    if (a < 0) {
        return -cubicRootUsingIteration(-a, epsilon);
    }
    if (a == 0) {
        return 0;
    }

    double x = a; // Начальное приближение
    double x_next;

    do {
        x_next = (1.0 / 3.0) * ((a / (x * x)) + 2 * x);
        if (fabs(x_next - x) < epsilon) {
            break;
        }
        x = x_next;
    } while (true);

    return x_next;
}

int main() {

    system("chcp 1251");

    double number;
    cout << "Введите число: ";
    cin >> number;

    double resultP = cubicRootUsingPow(number);
    cout << "Кубический корень из " << number << " равен " << resultP << endl;

    double resultI = cubicRootUsingIteration(number);
    cout << "Кубический корень из " << number << " равен " << resultI << endl;

    return 0;
}