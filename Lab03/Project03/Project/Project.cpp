// Реализация сложных алгоритмов с помощью функций

#include <iostream>

using namespace std;

long double firBinSearch(double a, int n) //алгоритм бинарного поиска для нахождения значения корня степени n
{
    double L = 0;
    double R = a;
    while (R - L > 1e-10)
    {
        double M = (L + R) / 2;
        if (pow(M, n) < a)
        {
            L = M;
        }
        else
        {
            R = M;
        }
    }
    return R;
}


int main()
{
    system("chcp 1251");

    double a;
    int n;

    cout << "Введите a(действительное число): "; cin >> a;
    cout << "Введите степень корня n(натуральное): "; cin >> n;

    double k = firBinSearch(a, n);

    cout << "Ответ: " << k;
}

