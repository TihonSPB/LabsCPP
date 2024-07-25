// Работа с различными треугольниками 

#include <iostream>
#include <cmath>

using namespace std;

// Функция для вычисления площади равностороннего треугольника
double calculateArea(double side) {
    return (sqrt(3) / 4) * side * side;
}

// Функция для вычисления площади разностороннего треугольника
double calculateArea(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {

    system("chcp 1251");

    int choice;
    cout << "Выберите тип треугольника:" << endl;
    cout << "1. Равносторонний треугольник" << endl;
    cout << "2. Разносторонний треугольник" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;

    if (choice == 1) {
        double side;
        cout << "Введите длину стороны равностороннего треугольника: ";
        cin >> side;
        double area = calculateArea(side);
        cout << "Площадь равностороннего треугольника: " << area << endl;
    }
    else if (choice == 2) {
        double a, b, c;
        cout << "Введите длины трех сторон разностороннего треугольника: ";
        cin >> a >> b >> c;
        double area = calculateArea(a, b, c);
        cout << "Площадь разностороннего треугольника: " << area << endl;
    }
    else {
        cout << "Неверный выбор." << endl;
    }

    return 0;
}