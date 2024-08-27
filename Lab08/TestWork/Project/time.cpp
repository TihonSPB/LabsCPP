#include <iomanip>
#include <iostream>
#include "time.h"

// Конструктор с параметрами
Time::Time(int h, int m, int s) {
    hours = h + m / 60 + s / 3600;
    minutes = m % 60 + (s % 3600) / 60;
    seconds = s % 60;
    hours %= 24; // Ограничиваем часы в пределах 24 часов
}

// Метод для вывода времени
void Time::displayTime() const {
    cout << setw(2) << setfill('0') << hours << ":"
        << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << seconds << endl;
}

// Метод для сложения двух объектов Time
Time Time::add(const Time& other) const {
    int totalSeconds = seconds + other.seconds;
    int totalMinutes = minutes + other.minutes + totalSeconds / 60;
    int totalHours = hours + other.hours + totalMinutes / 60;
    return Time(totalHours, totalMinutes % 60, totalSeconds % 60);
}