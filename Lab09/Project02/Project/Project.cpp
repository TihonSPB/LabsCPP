// Обработка исключительных операций
// Безопасное деление в цикле 

#include <iostream> 
#include <string> 

using namespace std;

//класс представляющий  ошибку, возникающую при делении на нуль
class DivideByZeroError
{
public:
    DivideByZeroError() : message("Деление на нуль") { }  void printMessage() const { cout << message << endl; }  private:
        string message;
};

// функция операции деления
float quotient(int numl, int num2)
{
    if (num2 == 0) // проверка делителя на 0.
        throw DivideByZeroError();
    return (float)numl / num2;
}


int main()
{
    system("chcp 1251");

    cout << "Введите числитель операции деления:\n";
    int number1;
    cin >> number1;

    for (int i = -10; i < 10; i++) //интервал изменения знаменателя, от -10 до 10
    {
        try
        {
            float result = quotient(number1, i);
            cout << "Частное равно " << result << endl;
        }
        catch (DivideByZeroError& error)
        {
            cout << "ОШИБКА: ";
            error.printMessage();
        }
    }

    return 0; // нормальное завершение программы      
}