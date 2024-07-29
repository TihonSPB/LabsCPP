// Структура Time

#include <iostream>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;

    // Функция для ввода времени
    void inputTime() {
        cout << "Введите часы: ";
        cin >> hours;
        cout << "Введите минуты: ";
        cin >> minutes;
        cout << "Введите секунды: ";
        cin >> seconds;
    }

    // Функция для вывода времени
    void displayTime() const {
        cout << hours << " часов, " << minutes << " минут, " << seconds << " секунд" << endl;
    }

    // Функция для вычисления общего количества секунд
    int totalSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    // Функция для сложения интервалов времени
    Time add(const Time& other) const {
        Time result;
        result.seconds = seconds + other.seconds;
        result.minutes = minutes + other.minutes + result.seconds / 60;
        result.hours = hours + other.hours + result.minutes / 60;
        result.seconds %= 60;
        result.minutes %= 60;
        result.hours %= 24; // Предполагаем, что время в пределах одного дня
        return result;
    }

    // Функция для вычитания интервалов времени
    Time subtract(const Time& other) const {
        Time result;
        int totalSec1 = totalSeconds();
        int totalSec2 = other.totalSeconds();
        int diffSec = totalSec1 - totalSec2;

        if (diffSec < 0) {
            diffSec += 86400; // Если результат отрицательный, добавляем 24 часа (в секундах)
        }

        result.hours = diffSec / 3600;
        result.minutes = (diffSec % 3600) / 60;
        result.seconds = diffSec % 60;
        return result;
    }
};

int main() {

    system("chcp 1251");

    Time time1, time2;

    cout << "Введите первое время:" << endl;
    time1.inputTime();

    cout << "Введите второе время:" << endl;
    time2.inputTime();

    cout << "Первое время: ";
    time1.displayTime();
    cout << "Общее количество секунд в первом времени: " << time1.totalSeconds() << endl;

    cout << "Второе время: ";
    time2.displayTime();
    cout << "Общее количество секунд во втором времени: " << time2.totalSeconds() << endl;

    Time sum = time1.add(time2);
    cout << "Сумма времен: ";
    sum.displayTime();

    Time diff = time1.subtract(time2);
    cout << "Разность времен: ";
    diff.displayTime();

    return 0;
}