// Использование шаблонных функций и классов
// Использование шаблонной функции для работы с кортежем любого размера

#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

// два варианта объявления шаблонного класса TuplePrinter (реализация называется рекурсивным экземпляром шаблона)
template<class Tuple, std::size_t N>
struct TuplePrinter {
	// статическую функция с именем print
	static void print(const Tuple& t)
	{
		TuplePrinter<Tuple, N - 1>::print(t);
		cout << ", " << get<N - 1>(t);
	}
};
template<class Tuple>
struct TuplePrinter<Tuple, 1> {
	// статическую функция с именем print
	static void print(const Tuple& t)
	{
		cout << get<0>(t);
	}
};

// функция вариативного шаблона.
template<class... Args>
void printTuple(const tuple<Args...>& t)
{
	cout << "(";
	TuplePrinter<decltype(t), sizeof...(Args)>::print(t); // вызывает функцию-член print() класса TuplePrinter
	cout << ")" << endl;
}

int main()
{
	// векторы для исходных данных кортежей
	vector<string> v1{ "one", "two", "three", "four", "five", "six" };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	vector<float> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

	auto t1 = std::make_tuple(v1[0], v1[1], v3[0]);
	auto t2 = std::make_tuple(v1[0], v1[1], v2[1], v3[0], v3[1]);

	printTuple(t1);
	printTuple(t2);

	return 0;
}