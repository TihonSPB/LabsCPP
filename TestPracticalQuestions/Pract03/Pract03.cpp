#include <iostream>

class Point {
public:
    int x, y;

    // Конструктор по умолчанию
    Point() : x(0), y(0) {}

    // Конструктор с параметрами
    Point(int x, int y) : x(x), y(y) {}

    // Оператор сложения
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // Оператор сложения с присваиванием
    Point& operator+=(const Point& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    // Оператор сложения с целым числом
    Point operator+(int value) const {
        return Point(x + value, y + value);
    }

    // Оператор присваивания
    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }
};

int main() {
    Point pt1(1, 1), pt2(2, 2), pt3;
    pt3 = pt1 + pt2; // pt3 теперь (3, 3)
    pt2 += pt1; // pt2 теперь (3, 3)
    pt3 = pt1 + 5; // pt3 теперь (6, 6)

    std::cout << "pt1: (" << pt1.x << ", " << pt1.y << ")\n";
    std::cout << "pt2: (" << pt2.x << ", " << pt2.y << ")\n";
    std::cout << "pt3: (" << pt3.x << ", " << pt3.y << ")\n";

    return 0;
}