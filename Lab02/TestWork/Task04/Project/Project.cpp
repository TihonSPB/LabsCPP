//Стрельба по мишени

#include <iostream>
#include <cmath>

int main() {

    system("chcp 1251");

    double x, y;
    // шаг радиуса мишени
    double radius = 10;
    // количество выстрелов
    int numberOfShots = 3;
    // количество очков
    int total = 0;

    for (int i = 0; i < numberOfShots; i++) {
        std::cout << "Введите данные о выстреле N" << (i + 1) << "." << std::endl;
        std::cout << "По оси X: ";
        std::cin >> x;
        std::cout << "По оси Y: ";
        std::cin >> y;

        double r = radius;

        for (int t = 10; t >= 0; t -= 5) {
            if (x * x + y * y <= r * r) {
                total += t;
                break;
            }
            r += radius;
        }
    }
    std::cout << "Вы набрали: " << total << " очков" << std::endl;

    return 0;
}