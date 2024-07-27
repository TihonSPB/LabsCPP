// Реализация ввода данных 
//

#include <iostream>
using namespace std;

// Функция для ввода двух целых чисел с проверкой корректности
bool Input(int& a, int& b) 
{
    cout << "Введите два целых числа: ";
    std::cin >> a >> b;

    // Проверяем, был ли ввод успешным
    if (cin.fail()) 
    {
        // Очищаем состояние ошибки
        cin.clear();
        // Игнорируем оставшиеся символы во входном буфере
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false; // Возвращаем false, если ввод некорректен
    }

    return true; // Возвращаем true, если ввод корректен
}

int main()
{
    int a, b;
    if (Input(a, b) == false) // if(!Input(a,b)) 
    {
        cerr << "error";
        return 1;
    }
    int s = a + b;

    cout << "Сумма: " << s << endl;

    return 0;
}
