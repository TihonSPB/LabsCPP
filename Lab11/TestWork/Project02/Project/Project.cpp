// Реализация сортировки точек в векторе
//

#include <iostream>
#include <vector>
#include <algorithm> // для алгоритма сортировки
#include <cmath>

using namespace std;

class Point {
public:
    // Конструктор с параметрами
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    // Функция расчета расстояния до центра координат
    double distanceToCenter() const {
        return sqrt(x * x + y * y);
    }

    // Перегрузка оператора << для вывода в поток
    friend ostream& operator<<(ostream& os, const Point& point);

    // Перегрузка оператора < для сравнения по расстоянию до центра координат
    bool operator<(const Point& other) const {
        return distanceToCenter() < other.distanceToCenter();
    }

private:
    double x, y;
};

// Определение функции для перегрузки оператора <<
ostream& operator<<(ostream& os, const Point& point) {
    os << "Point(" << point.x << ", " << point.y << ")";
    return os;
}

int main() {
    vector<Point> v;
    v.push_back(Point(1, 2));
    v.push_back(Point(10, 12));
    v.push_back(Point(21, 7));
    v.push_back(Point(4, 8));

    // Сортировка вектора точек по расстоянию до центра координат
    sort(v.begin(), v.end());

    // Вывод отсортированного вектора точек
    for (const auto& point : v) {
        cout << point << '\n';
    }

    return 0;
}