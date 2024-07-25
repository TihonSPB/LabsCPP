// Ввод-вывод данных 

#include <iostream>
#include <string>
using namespace std;
int main()
{
	system("chcp 1251"); //Для поддержки кириллицы

	string name;
	cout << "What is your name? "; //стандартный вывод на экран монитора
	//cin >> name; //cin - стандартный ввод – с клавиатуры
	getline(cin, name); //функция чтения строки
	cout << "Hello, " << name << "!\n";
}