// Безопасная реализация класса Time 
//

#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

class InvalidTimeError : public runtime_error {
public:
    InvalidTimeError(const string& message) : runtime_error(message) {}
};

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Конструктор по умолчанию
    Time() : hours(0), minutes(0), seconds(0) {}

    // Конструктор с параметрами
    Time(int h, int m, int s) {
        if (h < 0 || h >= 24) throw InvalidTimeError("Недопустимое значение часов");
        if (m < 0 || m >= 60) throw InvalidTimeError("Недопустимое значение минут");
        if (s < 0 || s >= 60) throw InvalidTimeError("Недопустимое значение секунд");

        hours = h + m / 60 + s / 3600;
        minutes = m % 60 + (s % 3600) / 60;
        seconds = s % 60;
        hours %= 24; // Ограничиваем часы в пределах 24 часов
    }

    // Метод для вывода времени
    void displayTime() const {
        cout << setw(2) << setfill('0') << hours << ":"
            << setw(2) << setfill('0') << minutes << ":"
            << setw(2) << setfill('0') << seconds << endl;
    }

    // Метод для сложения двух объектов Time
    Time add(const Time& other) const {
        int totalSeconds = seconds + other.seconds;
        int totalMinutes = minutes + other.minutes + totalSeconds / 60;
        int totalHours = hours + other.hours + totalMinutes / 60;
        return Time(totalHours, totalMinutes % 60, totalSeconds % 60);
    }
};

int main() {
    system("chcp 1251");

    try {
        // Создаем два инициализированных объекта
        const Time time1(10, 30, 45);
        const Time time2(5, 70, 120);

        // Создаем неинициализированный объект
        Time time3;

        // Складываем два инициализированных объекта и присваиваем результат третьему объекту
        time3 = time1.add(time2);

        // Выводим результат
        cout << "Время 1: ";
        time1.displayTime();
        cout << "Время 2: ";
        time2.displayTime();
        cout << "Время 3 (сумма Времени 1 и Времени 2): ";
        time3.displayTime();
    }
    catch (const InvalidTimeError& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}