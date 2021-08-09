#pragma once
#include <string>
#include "Worker.h"

using namespace std;

class Manager: public Worker {

public:
    Manager(string code, string name, unsigned int age): Worker(code, name, age) {
        type = 2;
    }

    virtual string responsibility();

    virtual string getType();
};