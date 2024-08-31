#include "PersonInterface.h"

void PersonInterface::run() {
    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n�������� ����. ����������, ������� �����.\n" << std::endl;
            continue;
        }
        std::cout << "\n";
        handleUserInput(choice);
        std::cout << "\n";
    }
}

void PersonInterface::displayMenu() {
    std::cout << "1. �������� ��������" << std::endl;
    std::cout << "2. ��������� � ����" << std::endl;
    std::cout << "3. ��������� �� �����" << std::endl;
    std::cout << "4. �������� ���� �����" << std::endl;
    std::cout << "5. �����" << std::endl;
}

void PersonInterface::handleUserInput(int choice) {
    std::string name, phone, occupation;
    switch (choice) {
    case 1:
        std::cout << "������� ���: ";
        std::cin >> name;
        std::cout << "������� �������: ";
        std::cin >> phone;
        std::cout << "������� ��� ������� (�������/�������������): ";
        std::cin >> occupation;
        if (occupation == "�������" || occupation == "�������������") {
            Person* newPerson = (occupation == "�������") ? static_cast<Person*>(new Student(name, phone)) : static_cast<Person*>(new Teacher(name, phone));
            PersonCollection::getInstance().addPerson(newPerson);
            std::cout << "������� ������� ��������." << std::endl;
        }
        else {
            std::cout << "�������� ��� �������. ���������� �����." << std::endl;
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
        std::cout << "�������� �����" << std::endl;
    }
}