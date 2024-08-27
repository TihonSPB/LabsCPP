//Применение полиморфизма
//Реализация полиморфного вызова

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Класс единицы хранения
class Item
{
private:
	string title; // название
	double price; // цена
public:
	virtual void getdata() // виртуальный метод ввода
	{
		cout << "\nВведите заголовок: ";
		cin >> title;
		cout << "Введите цену: ";
		cin >> price;
	}
	virtual void putdata() // виртуальный метод вывода
	{
		cout << "\nЗаголовок: " << title;
		cout << "\nЦена: " << price;
	}
};

// Класс производный от базового класса Item
class Paperbook : public Item
{
private:
	int pages; // переменная учета количества страниц
public:
	void getdata() // переопределение метода ввода базового класса Item
	{
		Item::getdata(); 
		cout << "Введите число страниц: ";
		cin >> pages;
	}
	void putdata() // переопределение метода вывода базового класса Item
	{
		Item::putdata(); 
		cout << "\nСтраниц: " << pages;
	}
};

// Класс производный от базового класса Item
class AudioBook : public Item
{
private:
	double time; // переменная учета времени звучания
public:
	void getdata() // переопределение метода ввода базового класса Item
	{
		Item::getdata(); 
		cout << "Введите время звучания : ";
		cin >> time;
	}
	void putdata() // переопределение метода вывода базового класса Item
	{
		Item::putdata();
		cout << "\nВремя звучания : " << time;
	}
};

int main()
{
	SetConsoleOutputCP(1251);

	Item* pubarr[100]; // массив указателей на класс Item
	int n = 0;
	char choice;

	// запрос у пользователя данные о выборе варианта заполнения данных
	do
	{
		cout << "\nВводить данные для книги или звукового файла(b / a) ? ";
		cin >> choice;
		if (choice == 'b')
			pubarr[n] = new Paperbook; // новый объект класса Paperbook
		else
			pubarr[n] = new AudioBook; // новый объект класса AudioBook
		pubarr[n++]->getdata();
		cout << "Продолжать((у / n) ? ";
		cin >> choice;
	} while (choice == 'y');

	// вывод данных о заполненных единицах хранения
	for (int j = 0; j < n; j++) //цикл по всем объектам
		pubarr[j]->putdata(); //вывести данные о публикации
	cout << endl;

	return 0;
}