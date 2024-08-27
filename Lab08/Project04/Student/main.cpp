// ќбъ¤вление и реализаци¤ класса. –еализаци¤  инкапсул¤ции.  онструкторы и деструкторы. 
// »спользование конструктора 

/* main.cpp */
#include <iostream> 
#include <string> 
#include "student.h" 

using namespace std;

int main()
{
	/*
	// ¬ыделение пам¤ти дл¤ объекта Student 
	Student* student02 = new Student;
	*/

	string name;
	string last_name;

	// ¬вод имени с клавиатуры 
	cout << "Name: ";
	getline(cin, name);

	// ¬вод фамилии 
	cout << "Last name: ";
	getline(cin, last_name);

	// ѕередача параметров конструктору 
	Student* student02 = new Student(name, last_name);

	/*
	// —охранение имени и фамилии в объект класса Students
	// дл¤  доступа к методам и свойствам объекта используетс¤ оператор косвенного обращени¤ Ч Ђ->ї
	student02->set_name(name); 
	student02->set_last_name(last_name);
	*/

	// ќценки 
	int scores[5];
	// —умма всех оценок 

	int sum = 0;

	// ¬вод промежуточных оценок 
	for (int i = 0; i < 5; ++i) {
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		// суммирование 
		sum += scores[i];
	}

	// —охран¤ем промежуточные оценки в объект класса Student 
	student02->set_scores(scores);

	// —читаем средний балл 
	float average_score = sum / 5.0;

	// —охран¤ем средний балл в объект класса Student 
	student02->set_average_score(average_score);

	// ¬ыводим данные по студенту 
	cout << "Average ball for " << student02->get_name() << " " << student02->get_last_name() << " is "
		<< student02->get_average_score() << endl;

	// ”даление объекта student из пам¤ти 
	delete student02;

	return 0;
}