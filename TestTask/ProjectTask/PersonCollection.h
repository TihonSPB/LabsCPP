#ifndef PERSONCOLLECTION_H
#define PERSONCOLLECTION_H

#include <vector>
#include <fstream>
#include <iostream>
#include "Person.h"

class PersonCollection {
private:
    std::vector<Person*> people;
    PersonCollection() {}
public:
    static PersonCollection& getInstance() {
        static PersonCollection instance;
        return instance;
    }

    void addPerson(Person* person) {
        people.push_back(person);
    }

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void displayAll() const;

    ~PersonCollection() {
        for (auto& person : people) {
            delete person;
        }
    }
};

#endif // PERSONCOLLECTION_H