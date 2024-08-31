#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
public:
    virtual std::string getName() const = 0;
    virtual std::string getPhone() const = 0;
    virtual std::string getOccupation() const = 0;
    virtual void displayInfo() const = 0;
    virtual ~Person() {}
};

class Student : public Person {
private:
    std::string name;
    std::string phone;
public:
    Student(const std::string& n, const std::string& p) : name(n), phone(p) {}
    std::string getName() const override { return name; }
    std::string getPhone() const override { return phone; }
    std::string getOccupation() const override { return "Студент"; }
    void displayInfo() const override {
        std::cout << "Имя: " << name << ", Телефон: " << phone << ", Род занятий: Студент" << std::endl;
    }
};

class Teacher : public Person {
private:
    std::string name;
    std::string phone;
public:
    Teacher(const std::string& n, const std::string& p) : name(n), phone(p) {}
    std::string getName() const override { return name; }
    std::string getPhone() const override { return phone; }
    std::string getOccupation() const override { return "Преподаватель"; }
    void displayInfo() const override {
        std::cout << "Имя: " << name << ", Телефон: " << phone << ", Род занятий: Преподаватель" << std::endl;
    }
};

#endif // PERSON_H