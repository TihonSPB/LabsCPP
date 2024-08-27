//Перегрузка операций
//Перегрузка операций операндов различных типов

#include <iostream>

using namespace std;

class Distance
{
private:
	int feet;
	float inches;

	const float MTF; // константа коэффициент перевода метров в футы
public:
	// конструктор по умолчанию
	Distance() : feet(0), inches(0.0), MTF(3.280833F) { }
	// конструктор с двумя параметрами
	Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) { }
	// конструктор с передачей ему параметра – значения вещественного типа
	Distance(float meters) : MTF(3.280833F)
	{
		float fltfeet = MTF * meters; // перевод в футы
		feet = int(fltfeet); // число полных футов
		inches = 12 * (fltfeet-feet); // остаток - это дюймы
	}

	void getdist()
	{
		cout << "\nВведите число футов : ";
		cin >> feet;
		cout << "\nВведите число дюймов : ";
		cin >> inches;
	}
	void showdist()
	{
		cout << feet << "\' - " << inches << "\"\n";
	}
	// операторная функция принемает значения объекта класса Distance, 
	// преобразовывает значение типа float (метры) и возвращает это значение
	operator float() const
	{
		float fracfeet = inches / 12;
		fracfeet += static_cast<float>(feet);
		return fracfeet / MTF;
	}

	Distance operator+ (const Distance&) const;
	friend Distance operator+ (const Distance&, float);
	friend Distance operator+ (float, const Distance&);

	friend Distance operator- (const Distance&, const Distance&);
	friend Distance operator- (const Distance&, float);
	friend Distance operator- (float, const Distance&);

	friend std::ostream& operator<< (std::ostream& out, const Distance& dist);
};

// операторная функция сложения двух расстояний
Distance Distance::operator+ (const Distance& d2) const
{
	int f = feet + d2.feet;
	float i = inches + d2.inches;
	if (i >= 12.0)
	{
		i -= 12.0;
		f++;
	}
	return Distance(f, i);
}

// перегружаемая дружественная функция для сложения расстояния и вещественного числа
Distance operator+ (const Distance& d, float meters)
{
	float totalMeters = static_cast<float>(d) + meters;
	return Distance(totalMeters);
}

// перегружаемая дружественная функция для сложения вещественного числа и расстояния
Distance operator+ (float meters, const Distance& d)
{
	return d + meters; // используем уже определенную функцию
}

// перегружаемая дружественная функция для вычитания двух расстояний
Distance operator- (const Distance& d1, const Distance& d2)
{
	int f = d1.feet - d2.feet;
	float i = d1.inches - d2.inches;
	if (i < 0.0)
	{
		i += 12.0;
		f--;
	}
	return Distance(f, i);
}

// перегружаемая дружественная функция для вычитания вещественного числа из расстояния
Distance operator- (const Distance& d, float meters)
{
	float totalMeters = static_cast<float>(d) - meters;
	return Distance(totalMeters);
}

// перегружаемая дружественная функция для вычитания расстояния из вещественного числа
Distance operator- (float meters, const Distance& d)
{
	float totalMeters = meters - static_cast<float>(d);
	return Distance(totalMeters);
}

// дружественная перегружаемая функция вывода <<
std::ostream& operator<< (std::ostream& out, const Distance& dist)
{
	out << dist.feet << "\' - " << dist.inches << "\"\n";
	return out;
}

int main() {

    system("chcp 1251");

	Distance dist1 = 2.35F;
	Distance dist2;

	dist2.getdist();

	cout << "\ndist1 = " << dist1;
	cout << "\ndist2 = " << dist2;


	float mtrs;

	mtrs = static_cast<float>(dist1);

	cout << "\ndist1 (m) = " << mtrs;

	mtrs = dist2;

	cout << "\ndist2 (m) = " << mtrs;

	// Пример использования новых операций
	Distance dist3 = dist1 + 2.8F;
	Distance dist4 = 2.8F + dist2;
	Distance dist5 = dist1 - 2.8F;
	Distance dist6 = 2.8F - dist2;

	cout << "\ndist3 (dist1 + 2.8) = " << dist3;
	cout << "\ndist4 (2.8 + dist2) = " << dist4;
	cout << "\ndist5 (dist1 - 2.8) = " << dist5;
	cout << "\ndist6 (2.8 - dist2) = " << dist6;
	
    return 0;
}