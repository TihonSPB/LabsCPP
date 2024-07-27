//Реализация динамического массива 

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

    int N;
    cout << "Введите размер массива: ";
    cin >> N;

    int* A = new int[N]; // создание динамического массива

    cout << "Введите элементы массива: ";
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int my_choose = 0;
    cout << "1. Сортировать по возрастанию\n";
    cout << "2. Сортировать по убыванию\n";
    cin >> my_choose;
    cout << "Исходные данные: ";

    show_array(A, N);

    bubble_sort(A, N, (from_f[my_choose - 1])); //(*from_f[my_choose - 1]) - разыменованный указатель с индексом my_choose - 1

    show_array(A, N);

    // Освобождение динамической памяти
    delete[] A;

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