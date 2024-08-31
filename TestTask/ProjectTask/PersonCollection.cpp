#include "PersonCollection.h"

void PersonCollection::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cout << "Не удалось открыть файл для записи." << std::endl;
    }
    else {
        for (const auto& person : people) {
            file << person->getName() << "," << person->getPhone() << "," << person->getOccupation() << std::endl;
        }
        file.close();
        std::cout << "Файл успешно записан." << std::endl;
    }
}

void PersonCollection::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Не удалось открыть файл для чтения." << std::endl;
        return;
    }
    std::string name, phone, occupation;
    int count = 0;
    while (std::getline(file, name, ',')) {
        std::getline(file, phone, ',');
        std::getline(file, occupation);
        if (occupation == "Студент") {
            addPerson(new Student(name, phone));
            count++;
        }
        else if (occupation == "Преподаватель") {
            addPerson(new Teacher(name, phone));
            count++;
        }
    }
    file.close();

    if (count > 0) {
        std::cout << "Успешно загружено " << count << " записей из файла." << std::endl;
    }
    else {
        std::cout << "Файл пуст или не содержит корректных данных." << std::endl;
    }
}

void PersonCollection::displayAll() const {
    if (people.empty()) {
        std::cout << "Нет записей для отображения." << std::endl;
    }
    else {
        for (const auto& person : people) {
            person->displayInfo();
        }
    }
}