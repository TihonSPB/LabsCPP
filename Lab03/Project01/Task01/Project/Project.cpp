// Использование функции при организации программы 
// Реализация процедуры

#include <iostream> 
#include <string>

using namespace std;

void privet(string); //прототип функции

int main()
{
	string name;
	cout << "What is your name?" << endl;
	cin >> name;
	privet(name);
	return 0;
}

void privet(string name) // функция
{
	cout << name << ", " << "hello!" << endl;
}
