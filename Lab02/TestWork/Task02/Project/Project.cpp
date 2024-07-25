// Проверка номера СНИЛС

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    system("chcp 1251"); // Установка кодировки для корректного отображения русских символов

    string strSnils;
    bool validInput = false;

    while (!validInput) {
        cout << "Введите номер СНИЛС (11 цифр): ";
        cin >> strSnils;

        // Проверка длины СНИЛС
        if (strSnils.length() != 11) {
            cout << "СНИЛС состоит из 11 цифр." << endl;
            continue;
        }

        bool allDigits = true;
        // Проверка, что все символы являются цифрами
        for (char c : strSnils) {
            if (!isdigit(c)) {
                cout << "Введенная строка должна содержать только цифры." << endl;
                allDigits = false;
                break;
            }
        }
        if (!allDigits) continue;

        bool noTripleDigits = true;
        // Проверка на наличие более чем двух одинаковых цифр подряд в основной части номера
        for (int i = 0; i < 9; ++i) {
            if (strSnils[i] == strSnils[i + 1] && strSnils[i] == strSnils[i + 2]) {
                cout << "В основной части номера не может быть более чем двух одинаковых цифр подряд." << endl;
                noTripleDigits = false;
                break;
            }
        }
        if (!noTripleDigits) continue;

        int sum = 0;
        // Расчет суммы произведений цифр на их позиции
        for (int i = 0; i < 9; ++i) {
            sum += (strSnils[i] - '0') * (9 - i);
        }

        int controlNumber;
        // Определение контрольного числа
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

        // Извлечение предоставленного контрольного числа из строки
        int providedControlNumber = stoi(strSnils.substr(9, 2));
        // Проверка соответствия рассчитанного и предоставленного контрольных чисел
        if (controlNumber == providedControlNumber) {
            validInput = true;
            cout << "СНИЛС корректен." << endl;
        }
        else {
            cout << "СНИЛС некорректен." << endl;
        }
    }

    return 0;
}

