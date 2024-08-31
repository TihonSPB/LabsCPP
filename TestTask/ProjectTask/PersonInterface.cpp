#include "PersonInterface.h"

void PersonInterface::run() {
    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nНеверный ввод. Пожалуйста, введите число.\n" << std::endl;
            continue;
        }
        std::cout << "\n";
        handleUserInput(choice);
        std::cout << "\n";
    }
}

void PersonInterface::displayMenu() {
    std::cout << "1. Добавить человека" << std::endl;
    std::cout << "2. Сохранить в файл" << std::endl;
    std::cout << "3. Загрузить из файла" << std::endl;
    std::cout << "4. Показать всех людей" << std::endl;
    std::cout << "5. Выход" << std::endl;
}

void PersonInterface::handleUserInput(int choice) {
    std::string name, phone, occupation;
    switch (choice) {
    case 1:
        std::cout << "Введите имя: ";
        std::cin >> name;
        std::cout << "Введите телефон: ";
        std::cin >> phone;
        std::cout << "Введите род занятий (Студент/Преподаватель): ";
        std::cin >> occupation;
        if (occupation == "Студент" || occupation == "Преподаватель") {
            Person* newPerson = (occupation == "Студент") ? static_cast<Person*>(new Student(name, phone)) : static_cast<Person*>(new Teacher(name, phone));
            PersonCollection::getInstance().addPerson(newPerson);
            std::cout << "Человек успешно добавлен." << std::endl;
        }
        else {
            std::cout << "Неверный род занятий. Попробуйте снова." << std::endl;
        }
        break;
    case 2:
        PersonCollection::getInstance().saveToFile("people.txt");
        break;
    case 3:
        PersonCollection::getInstance().loadFromFile("people.txt");
        break;
    case 4:
        PersonCollection::getInstance().displayAll();
        break;
    case 5:
        exit(0);
    default:
        std::cout << "Неверный выбор" << std::endl;
    }
}