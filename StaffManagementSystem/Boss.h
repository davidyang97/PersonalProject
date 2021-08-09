#pragma once
#include <string>
#include "Worker.h"

using namespace std;

class Boss: public Worker {

public:
    Boss(string code, string name, unsigned int age): Worker(code, name, age) {
        type = 3;
    }

    virtual string responsibility();

    virtual string getType();
};