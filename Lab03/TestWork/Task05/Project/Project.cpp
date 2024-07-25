// Применение рекурсии для перевода целого числа в двоичный код 

#include <iostream>

using namespace std;

void decimal_to_binary(int num) {
    if (num > 0) {
        decimal_to_binary(num / 2);
        cout << num % 2;
    }
}

int main() {

    system("chcp 1251");

    int number;
    cout << "Введите целое положительное число: ";
    cin >> number;

    if (number == 0) {
        cout << "Двоичное представление числа 0 это: 0" << endl;
    }
    else {
        cout << "Двоичное представление числа " << number << " это: ";
        decimal_to_binary(number);
        cout << endl;
    }

    return 0;
}