#include "addressbook.h"

AddressBook::AddressBook() {
	
} 

bool AddressBook::addElement(Person person) {
	if(this->personList.find(person.name) != personList.end()) {
		return false;
	} 
	
	personList.insert(pair<string, Person>(person.name, person));
	
	return true;
}

bool AddressBook::deleteElement(string name) {
	unordered_map<string, Person>::iterator it = this->personList.find(name);
	if(it == personList.end()) {
		return false;
	} 
	
	personList.erase(it);
	
	return true;
}

bool AddressBook::modifyElement(Person person) {
	if(deleteElement(person.name)) {
		addElement(person);
		return true;
	}
	else {
		return false;
	}
}

vector<Person> AddressBook::listElement() {
	unordered_map<string, Person>::iterator it;
	vector<Person> result;
	for(it = this->personList.begin(); it != this->personList.end(); it++) {
		result.push_back(it->second);
	}	
	return result;
}

Person AddressBook::findElement(string name) {
	Person person;
	unordered_map<string, Person>::iterator it = this->personList.find(name);
	if(it == personList.end()) {
		return person;
	} 
	else {
		person = personList[name];
		return person;
	}
}  

void AddressBook::clearElement() {
	this->personList.clear();
}
