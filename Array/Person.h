#pragma once

#include <string>

using namespace std;

class Person {
public:
    Person();

    Person(string name, int age);

    string name;
    int age;

};