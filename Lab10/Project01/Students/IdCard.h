// заголовочный файл IdCard.h в нем только прототипы методов файла IdCard.cpp

/* IdCard.h */
#pragma once
#include <string>

using namespace std;

class IdCard
{
private:
	int number; //номер карточки
	string category; //статус (категорию)
public:
	// конструкторы
	IdCard();
	IdCard(int);
	IdCard(int, string);
	// методы доступа к полям
	void setNumber(int newNumber);
	int getNumber();
	void setCategory(string cat);
	string getCategory();
};