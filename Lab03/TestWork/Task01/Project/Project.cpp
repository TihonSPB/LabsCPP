//Проверка номера СНИЛС

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

bool isValidSnils(string strSnils) {
    string cleanedSnils;
    for (char c : strSnils) {
        if (isdigit(c)) {
            cleanedSnils.push_back(c);
        }
        else if (c != ' ' && c != '-') {
            return false; // Если встретился символ, отличный от цифры, пробела или дефиса
        }
    }

    // Проверка длины и наличия только цифр
    if (cleanedSnils.length() != 11) return false;

    // Проверка на более чем две одинаковые цифры подряд
    for (int i = 0; i < 9; ++i) {
        if (cleanedSnils[i] == cleanedSnils[i + 1] && cleanedSnils[i] == cleanedSnils[i + 2]) {
            return false;
        }
    }

    // Расчет контрольного числа
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        sum += (cleanedSnils[i] - '0') * (9 - i);
    }

    int controlNumber;
    if (sum < 100) {
        controlNumber = sum;
    }
    else if (sum == 100 || sum == 101) {
        controlNumber = 0;
    }
    else {
        int remainder = sum % 101;
        controlNumber = (remainder < 100) ? remainder : 0;
    }

    // Проверка контрольного числа
    int providedControlNumber = stoi(cleanedSnils.substr(9, 2));
    return controlNumber == providedControlNumber;
}

int main() {
    system("chcp 1251");
    string strSnils;
    bool validInput = false;

    while (!validInput) {
        cout << "Введите номер СНИЛС (11 цифр): ";
        getline(cin, strSnils); // Используем getline для считывания всей строки

        if (isValidSnils(strSnils)) {
            validInput = true;
            cout << "СНИЛС корректен." << endl;
        }
        else {
            cout << "СНИЛС некорректен." << endl;
        }
    }
    return 0;
}