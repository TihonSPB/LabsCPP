// Определение суперпростого числа 

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    system("chcp 1251");

    int number;
    cout << "Введите число для проверки: "; cin >> number;

    bool isSuperPrime = true;
    while (number > 0) {
        // Проверка, является ли number простым
        if (number <= 1) {
            isSuperPrime = false;
            break;
        }
        if (number <= 3) {
            number /= 10;
            continue;
        }
        if (number % 2 == 0 || number % 3 == 0) {
            isSuperPrime = false;
            break;
        }
        for (int i = 5; i * i <= number; i += 6) {
            if (number % i == 0 || number % (i + 2) == 0) {
                isSuperPrime = false;
                break;
            }
        }
        if (!isSuperPrime) break;
        number /= 10;
    }

    if (isSuperPrime) {
        cout << "Число является суперпростым." << endl;
    }
    else {
        cout << "Число не является суперпростым." << endl;
    }

    return 0;
}