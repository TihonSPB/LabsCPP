//Использование цикла с предусловием 

#include <iostream>
using namespace std;

int main()
{
    system("chcp 1251");

    int a, b, temp;

    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;

    {
        if (a > b)
            a -= b; // аналогично выражению a = a - b 
        else
            b -= a;
    }

    cout << "НОД = " << a << endl;
}
