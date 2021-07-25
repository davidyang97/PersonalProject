#ifndef _STRING_H_
#define _STRING_H_

#include <string>

#endif // string

#ifndef PS_H
#define PS_H

using namespace std;

class Person {
	public:
		string name;
		int age;
		int sex;
		string address;
		string phone;
		Person();
		Person(string &name, int &age, int &sex, string &address, string &phone);
};

#endif // Person
