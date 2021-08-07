#pragma once
#include <string>
#include "Worker.h"

using namespace std;

class Staff: public class Worker {

public:
    Staff(string code, string name, unsigned int age)：Worker(string code, string name, unsigned int age) {
        
    }

    string responsibility();

    string getType();

    string showInfo();
}