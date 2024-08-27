// Реализация наследования
// 02 Создание объекта класса student
// 03 Работа с классом teacher
// main.cpp

#include <iostream>
#include <vector>
#include "human.h"
#include "student.h"
#include "teacher.h"

int main()
{
	system("chcp 1251");

	// Оценки студента
	std::vector<int> scores;
	// Добавление оценок студента в вектор
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(4);
	scores.push_back(4);
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);

	// Создание студента – объект класса student 
	student* stud = new student("Петров", "Иван", "Алексеевич", scores);

	// Вывод полного имени студента используя унаследованный метод класса human
	std::cout << stud->get_full_name() << std::endl;

	// Вывод среднего балла студента
	std::cout << "Средний балл : " << stud->get_average_score() << std::endl;


	// Количество учебных часов за семестр у преподавателя
	unsigned int teacher_work_time = 40;

	// Создание преподавателя – объект класса teacher
	teacher* tch = new teacher("Сергеев", "Дмитрий", "Сергеевич", teacher_work_time);

	// Вывод полного имени преподавателя используя унаследованный метод класса human
	std::cout << tch->get_full_name() << std::endl;

	// Вывод количества учебных часов у преподавателя
	std::cout << "Количество часов: " << tch->get_work_time() << std::endl;

	return 0;
}