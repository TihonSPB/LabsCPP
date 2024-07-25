// Перегрузка функций 

#include <iostream> 
#include <string>

using namespace std;

void privet(string); //прототип функции

void privet(string name) //функция
{
	cout << name << ", " << "hello!" << endl;
}

void privet(string name, int k) //перегрузка функции
{
	cout << name << ", " << "hello! " << "you input " << k << endl;
}

int main()
{
	string name;
	int k;
	cout << "What is your name?" << endl;
	cin >> name;
	cout << "Input number:" << endl;
	cin >> k;

	privet(name);
	privet(name, k);

	return 0;
}