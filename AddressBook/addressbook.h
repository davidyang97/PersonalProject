#ifndef _STRING_H_
#define _STRING_H_

#include <string>

#endif // string

#ifndef _MAP_H_
#define _MAP_H_

#include <unordered_map>

#endif // unordered_map

#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <vector>

#endif // vector

#ifndef AB_H
#define AB_H

#include "person.h"

class AddressBook {
	private:
		unordered_map<string, Person> personList;
	public:
		AddressBook();
		bool addElement(Person person);
		bool deleteElement(string name);
		bool modifyElement(Person person);
		vector<Person> listElement();
		Person findElement(string name);
		void clearElement(); 
};

#endif // AddressBook
