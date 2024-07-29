// Решение квадратного уравнения 
//

#include <iostream>
#include <cmath>
#include <tuple>
using namespace std;

using Tuple = tuple<double, double, bool>;

// Функция для решения квадратного уравнения
Tuple solveQuadratic(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant >= 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        return make_tuple(root1, root2, true);
    }
    else {
        // Возвращаем NaN для корней и false для флага, если корни комплексные
        return make_tuple(NAN, NAN, false);
    }
}

void printTupleOfRoots(Tuple r)
{
    if (get<2>(r)) {
        cout << "Корни уравнения: " << get<0>(r) << " и " << get<1>(r) << endl;
    }
    else {
        cout << "Уравнение имеет комплексные корни." << endl;
    }
}

int main() {

    system("chcp 1251");

    double a, b, c;

    cout << "Введите коэффициенты квадратного уравнения (a, b, c): ";
    cin >> a >> b >> c;

    auto roots = solveQuadratic(a, b, c);

    printTupleOfRoots(roots);

    return 0;
}