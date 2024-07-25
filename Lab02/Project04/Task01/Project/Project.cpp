// Расчет суммы чисел на заданном интервале

#include <iostream>
using namespace std;

int main()
{
    int k = 20, m = 30, s = 0;
    for (int i = 1;i <= 100;i++)
    {
        if ((i > k) && (i < m))
            continue;
        s += i;
    }
    cout << s;
}
