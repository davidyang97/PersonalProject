#include "person.h"

Person::Person() {
	
}

Person::Person(string &name, int &age, int &sex, string &address, string &phone) {
	this->name = name;
	this->age = age;
	this->sex = sex;
	this->address = address;
	this->phone = phone;
}

