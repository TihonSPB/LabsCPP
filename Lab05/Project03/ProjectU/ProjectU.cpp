// Использование указателя на функцию 
// Использование массива указателей на функции 

#include <iostream>
using namespace std;

//прототипы функций
void show_array(const int Arr[], const int N);
bool from_min(const int a, const int b);
bool from_max(const int a, const int b);
void bubble_sort(int Arr[], const int N, bool (*compare)(int a, int b));

int main()
{
    system("chcp 1251");

    bool (*from_f[2])(int, int) = { from_min,from_max }; //массив из двух указателей на функции, где функции принимают два целых аргумента, а тип возвращаемого параметра – bool

    const int N = 10;
    int my_choose = 0;
    int A[N] = { 9,8,7,6,1,2,3,5,4,9 };
    cout << "1. Сортировать по возрастанию\n";
    cout << "2. Сортировать по убыванию\n";
    cin >> my_choose;
    cout << "Исходные данные: ";

    show_array(A, N);

    bubble_sort(A, N, (from_f[my_choose - 1])); //(*from_f[my_choose - 1]) - разыменованный указатель с индексом my_choose - 1

    /*
    //поведения программы в зависимости от выбора пользователя
    switch (my_choose)
    {
    case 1: bubble_sort(A, N, from_min); break;
    case 2: bubble_sort(A, N, from_max); break;
    default: cout << "\rНеизвестная операция ";
    }
    */

    show_array(A, N);

    return 0;
}

//функция вывода
void show_array(const int Arr[], const int N)
{
    for (int i = 0; i < N; i++)
        cout << Arr[i] << " ";
    cout << "\n";
}

//функции, определяющие направление сравнения
bool from_min(const int a, const int b)
{
    return a > b;
}
bool from_max(const int a, const int b)
{
    return a < b;
}

//функция обменной (пузырьковой) сортировки
//параметры, передаваемые в функцию: 
//  Arr[]; N - константный массив и его размер
//  (*compare)(int a, int b) - параметр булевого типа должен принимать 
//                             указатель на функцию с двумя параметрами, 
//                             причем сам указатель заключен в круглые скобки, 
//                             а  параметры в отдельные круглые скобки
void bubble_sort(int Arr[], const int N, bool (*compare)(int a, int b)) {
    for (int i = 1;i < N;i++)
    {
        for (int j = 0;j < N - 1;j++)
        {
            if ((*compare)(Arr[j], Arr[j + 1]))
                swap(Arr[j], Arr[j + 1]);
        }
    }
}