// Рекурсивная функция суммы ряда S = 5 + 10 + 15 + … + 5·n, при n > 0.

#include <iostream>
#include<cmath>

using namespace std;

int summN(int n)
{
    int num = 5;
    if (n == 1) { // выход из рекурсии 
        cout << num; 
        return num; 
    } 
    else {
        cout << n * num << " + ";
        return (n * num + summN(n - 1));
    }        
}

int main()
{
    system("chcp 1251");

    int number;
    cout << "Введите число: "; cin >> number;

    cout << "S = ";
    int s = summN(number);
    cout << " = " << s;
}