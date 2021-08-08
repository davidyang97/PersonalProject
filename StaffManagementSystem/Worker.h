#pragma once
#include <string>

using namespace std;

class Worker {
    
public:
    string code;
    string name;
    unsigned int age;

    Worker(string code, string name, unsigned int age);

    virtual string responsibility() = 0;

    virtual string getType() = 0;

    virtual string showInfo() = 0;
};
