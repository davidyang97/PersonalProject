#include <string>

using namespace std;

class Person {
public:
    Person() {

    }

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    string name;
    int age;

};