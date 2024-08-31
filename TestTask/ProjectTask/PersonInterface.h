#ifndef PERSONINTERFACE_H
#define PERSONINTERFACE_H

#include <iostream>
#include <limits>
#include "PersonCollection.h"

class PersonInterface {
public:
    void run();
    void displayMenu();
    void handleUserInput(int choice);
};

#endif // PERSONINTERFACE_H
