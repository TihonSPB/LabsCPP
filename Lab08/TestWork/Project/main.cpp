//Класс Time 

#include <iostream>
#include "time.h"

using namespace std;

int main() {

    system("chcp 1251");

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

    return 0;
}