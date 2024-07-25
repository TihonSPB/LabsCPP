// Применение рекурсивной функции 
// Сумма чисел

#include <iostream>

using namespace std;

int addNumders(int n)
{
    if (n == 1) return 1; // выход из рекурсии 
    else return (n + addNumders(n - 1));
}

int addNumders(int n, int s)
{
    int sum = 0;
    for (int i = s; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

int main()
{
    system("chcp 1251");

    int number(1);
    int start(1);
    cout << "Введите первое число: "; cin >> start;
    cout << "Введите число: "; cin >> number;
    

    int sum = addNumders(number);
    int sumS = addNumders(number, start);

    cout << "Сумма чисел от 1 до " << number << " = " << sum << endl;
    cout << "Сумма чисел от " << start << " до " << number << " = " << sumS << endl;
}
