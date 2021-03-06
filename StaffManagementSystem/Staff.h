#pragma once
#include <string>

#include "Worker.h"

using namespace std;

class Staff: public Worker {

public:
    Staff(string code, string name, unsigned int age): Worker(code, name, age) {
        type = 1;
    }

    virtual string responsibility();

    virtual string getType();
};
