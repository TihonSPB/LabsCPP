#pragma once

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Конструктор по умолчанию
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int, int, int);

    void displayTime() const;

    Time add(const Time&) const;
};