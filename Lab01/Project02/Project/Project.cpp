// Преобразование типов данных 

#include <iostream>
using namespace std;
int main()
{
	//ввод:
	//25вася
	//7

	system("chcp 1251");

	string name;
	cout << "Введите свое имя\n";

	double a, b;
	cout << "Введите a и b:\n";
	cin >> a; // ввод с клавиатуры значения a

	cin >> name;

	cin >> b; // ввод с клавиатуры значения b
	double x = a / b; // вычисление значения x
	//int x = a / b; // вычисление значения x

	cout << "Привет, " << name << "!\n";

	cout.precision(3); //формат вывода, с точностью до трех разрядов после запятой

	cout << "\nx = " << x << endl; //вывод результата на экран
	cout << "расчет объема занимаемой памяти : a/b = " << sizeof(a / b) << ends << " ; расчет объема занимаемой памяти : x = " << sizeof(x) << endl;
	return 0;
}