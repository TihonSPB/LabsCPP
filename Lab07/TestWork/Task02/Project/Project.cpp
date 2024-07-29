//Решение квадратного уравнения 

#include <iostream>
#include <cmath>
using namespace std;

// Структура для хранения корней квадратного уравнения
struct QuadraticSolution {
    double root1;
    double root2;
};

// Функция для решения квадратного уравнения
QuadraticSolution solveQuadratic(double a, double b, double c) {
    QuadraticSolution solution;
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        solution.root1 = (-b + sqrt(discriminant)) / (2 * a);
        solution.root2 = (-b - sqrt(discriminant)) / (2 * a);
    }
    else if (discriminant == 0) {
        solution.root1 = solution.root2 = -b / (2 * a);
    }
    else {
        // Комплексные корни не обрабатываются в этом примере
        solution.root1 = solution.root2 = NAN;
    }

    return solution;
}

int main() {
    system("chcp 1251");

    double a, b, c;

    cout << "Введите коэффициенты квадратного уравнения (a, b, c): ";
    cin >> a >> b >> c;

    QuadraticSolution solution = solveQuadratic(a, b, c);

    if (isnan(solution.root1)) {
        cout << "Уравнение имеет комплексные корни." << endl;
    }
    else {
        cout << "Корни уравнения: " << solution.root1 << " и " << solution.root2 << endl;
    }

    return 0;
}