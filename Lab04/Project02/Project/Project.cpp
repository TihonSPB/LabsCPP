// Реализация функции обмена значений 
//

#include <iostream>

using namespace std;

void swap(int*, int*); //прототип принимает два указателя
void swap(int&, int&); //прототип принимает две ссылки

void print(double x, double y) //вывод
{
    cout << "x = " << x << "; y = " << y << endl;
}

int main()
{
    system("chcp 1251");

    int x = 5, y = 10;
    print(x, y);

    swap(&x, &y);
    cout << "Передача в функцию параметра указателя: ";
    print(x, y);

    swap(x, y);
    cout << "Передача в функцию параметра ссылки: ";
    print(x, y);
}

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void swap(int& x, int& y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}


