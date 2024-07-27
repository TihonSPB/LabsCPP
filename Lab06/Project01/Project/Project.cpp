// Работа с файлами 
// Запись и чтение данных из бинарного файла 

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    double sum = 0; // сумма чисел
    int const n = 100; // размер массива
    double nums[n]; // массив

    // заполнение массива случайными числами
    for (int i = 0; i < n; i++)
    {
        nums[i] = (rand() % 100);
    }

    /////////////////
    ////Запись в файл

    // ofstream — класс из библиотеки C++, представляет собой поток вывода в файл.
    // out — объект для записи данных в файл.
    // out("test", ios::out | ios::binary) — вызов конструктора класса ofstream, открывает файл с именем "test" для записи.
    // ios::out — флаг, файл открывается для записи
    // ios::binary — флаг, файл открывается в бинарном режиме, а не в текстовом.
    ofstream out("test", ios::out | ios::binary); 
    if (!out) { // успешно ли открыт файл
        cout << "Файл открыть невозможно\n";
        return 1;
    }

    // write — метод класса ofstream, записывает данные в файл
    // (char*)nums — приведение типа массива nums к типу char*. метод write ожидает указатель на char
    // sizeof(nums) — размер массива nums в байтах. сколько байтов нужно записать в файл.
    out.write((char*)nums, sizeof(nums));

    // закрываем поток
    out.close();

    /////////////////
    ////Чтение файла

    // ifstream — класс из библиотеки C++, представляет собой поток ввода из файла
    // in("test", ios::in | ios::binary) — вызов конструктора класса ifstream, открывает файл с именем "test" для чтения.
    // ios::in — флаг, файл открывается для чтения.
    // ios::binary — флаг, файл открывается в бинарном режиме, а не в текстовом.
    ifstream in("test", ios::in | ios::binary);
    if (!in) {
        cout << "Файл открыть невозможно";
        return 1;
    }

    // read — вызов метода read класса ifstream, читает данные из файла.
    // (char*)&nums — приведение типа указателя на массив nums к типу char*
    // sizeof(nums) — это размер массива nums в байтах
    in.read((char*)&nums, sizeof(nums));

    // обработка полученных данных и вывод результаты на экран
    int k = sizeof(nums) / sizeof(double);
    for (int i = 0; i < k; i++)
    {
        sum = sum + nums[i];
        cout << nums[i] << ' ';
    }
    cout << "\nsum = " << sum << endl;

    // закрываем поток
    in.close();
}
