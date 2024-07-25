//Применение рекурсивной функции 
//Алгоритм Евклида 

#include <iostream>

using namespace std;

int addNumders(int n) //Сумма чисел от 1 до n
{
    if (n == 1) return 1; // выход из рекурсии 
    else return (n + addNumders(n - 1));
}

int addNumders(int n, int s) //Сумма чисел от s до n
{
    int sum = 0;
    for (int i = s; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

int gcd(int m, int n) //алгоритм Евклида
{
    if (n == 0) return m;
    return gcd(n, m % n);
}

int main()
{
    system("chcp 1251");

    int start(1);
    int number(1);
    cout << "Введите первое число: "; cin >> start;
    cout << "Введите число: "; cin >> number;

    int sum = addNumders(number);
    int sumS = addNumders(number, start);
    int evkl = gcd(start, number);

    cout << "Сумма чисел от 1 до " << number << " = " << sum << endl;
    cout << "Сумма чисел от " << start << " до " << number << " = " << sumS << endl;
    cout << "Наибольший общий делитель " << start << " и " << number << " = " << evkl << endl;
}
