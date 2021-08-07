#pragma once
#include <string>

using namespace std;

class Worker {
    
public:
    string code;
    string name;
    unsigned int age;

    Worker(string code, string name, unsigned int age);

    string responsibility() = 0;

    string getType() = 0;

    string showInfo() = 0;
};