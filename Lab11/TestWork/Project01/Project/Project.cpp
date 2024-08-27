// Перегрузка операторов в классе Time
//

#include <iostream>
#include <stdexcept>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    // Вспомогательный метод для нормализации времени
    void normalize() {
        while (seconds >= 60) {
            seconds -= 60;
            minutes += 1;
        }
        while (minutes >= 60) {
            minutes -= 60;
            hours += 1;
        }
        while (seconds < 0) {
            seconds += 60;
            minutes -= 1;
        }
        while (minutes < 0) {
            minutes += 60;
            hours -= 1;
        }
    }

public:
    // Конструктор
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    // Перегрузка оператора сложения
    Time operator+(const Time& other) const {
        Time result(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
        result.normalize();
        return result;
    }

    // Перегрузка оператора вычитания
    Time operator-(const Time& other) const {
        Time result(hours - other.hours, minutes - other.minutes, seconds - other.seconds);
        result.normalize();
        return result;
    }

    // Перегрузка оператора сложения с вещественным числом
    Time operator+(double value) const {
        int totalSeconds = static_cast<int>(value * 3600);
        Time result(hours, minutes, seconds + totalSeconds);
        result.normalize();
        return result;
    }

    // Дружественная функция для перегрузки сложения вещественного числа и объекта Time
    friend Time operator+(double value, const Time& t) {
        return t + value;
    }

    // Перегрузка оператора сравнения
    bool operator==(const Time& other) const {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
    }

    bool operator!=(const Time& other) const {
        return !(*this == other);
    }

    // Метод для вывода времени
    void display() const {
        std::cout << hours << " ч., " << minutes << " м., " << seconds << " с." << std::endl;
    }
};

int main() {

    system("chcp 1251");

    Time t1(3, 20, 15);
    Time t2(1, 45, 30);

    std::cout << "t1 = ";
    t1.display();
    std::cout << "t2 = ";
    t2.display();

    Time sum = t1 + t2;
    std::cout << "t1 + t2 = ";
    sum.display(); // 5 ч., 5 м., 45 с.

    Time diff = t1 - t2;
    std::cout << "t1 - t2 = ";
    diff.display(); // 1 ч., 34 м., 45 с.

    Time t3 = t1 + 2.5; // 2.5 часы как double
    std::cout << "t1 + 2.5 = ";
    t3.display(); // 5 ч., 50 м., 15 с.

    Time t4 = 1.25 + t2; // 1.25 часы как double
    std::cout << "1.25 + t2 = ";
    t4.display(); // 3 ч., 0 м., 30 с.

    if (t1 == t2) {
        std::cout << "t1 и t2 равны" << std::endl;
    }
    else {
        std::cout << "t1 и t2 не равны" << std::endl;
    }

    return 0;
}