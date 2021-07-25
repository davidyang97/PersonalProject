#include <iostream>
#include "person.h"
#include "addressbook.h"

using namespace std;

void showMenu() {
	cout << endl << "*********ͨѶ¼����ϵͳ*********" << endl;
	cout << "*******   1. �����ϵ��  *******" << endl;
	cout << "*******   2. ɾ����ϵ��  *******" << endl;
	cout << "*******   3. �޸���ϵ��  *******" << endl;
	cout << "*******   4. ��ʾ��ϵ��  *******" << endl;
	cout << "*******   5. �����ϵ��  *******" << endl;
	cout << "*******   0. �˳�        *******" << endl;
	cout << "********************************" << endl << endl;
}

void addPerson(AddressBook &addressbook) {
	string name;
	cout << "���������֣�" << endl;
	cin >> name;
	int age;
	cout << "���������䣺" << endl;
	cin >> age;
	int sex = 0;
	while(sex != 1 && sex != 2) {
		cout << "�������Ա� 1-�� 2-Ů��" << endl;
		cin >> sex;
	}
	string address;
	cout << "�������ַ��" << endl;
	cin >> address;
	string phone;
	cout << "������绰���룺" << endl;
	cin >> phone;
	
	Person person(name, age, sex, address, phone);
	if(!addressbook.addElement(person)) {
		cout << "���д���ϵ�ˣ�" << endl;
	}
	else {
		cout << "��ӳɹ���" << endl;
	} 
}

void deletePerson(AddressBook &addressbook) {
	string name;
	cout << "���������֣�" << endl;
	cin >> name;
	if(!addressbook.deleteElement(name)) {
		cout << "δ�鵽����ϵ�ˣ�" << endl;
	}
	else {
		cout << "ɾ���ɹ���" << endl;
	} 
}

void modifyPerson(AddressBook &addressbook) {
	string name;
	cout << "���������֣�" << endl;
	cin >> name;
	int age;
	cout << "���������䣺" << endl;
	cin >> age;
	int sex = 0;
	while(sex != 1 && sex != 2) {
		cout << "�������Ա� 1-�� 2-Ů��" << endl;
		cin >> sex;
	}
	string address;
	cout << "�������ַ��" << endl;
	cin >> address;
	string phone;
	cout << "������绰���룺" << endl;
	cin >> phone;
	
	Person person(name, age, sex, address, phone);
	
	if(!addressbook.modifyElement(person)) {
		cout << "δ�鵽����ϵ�ˣ�" << endl;
	}
	else {
		cout << "�޸ĳɹ���" << endl;
	} 
}

void listPerson(AddressBook &addressbook) {
	vector<Person> list = addressbook.listElement();
	
	cout << "��ϵ���б����£�" << endl; 
	int i = 0;
	for(auto it = list.begin(); it != list.end(); it++) {
		int sex = it->sex;
		string temp;
		if(sex == 1) temp = "��";
		else temp = "Ů";
		cout << it->name << "\t" << it->age << "\t" << temp << "\t" << it->address << "\t" << it->phone << endl;
		i++;
	}
	cout << "��ʾ��ϣ�һ��" << i << "����¼" << endl; 
}

void clearPerson(AddressBook &addressbook) {
	addressbook.clearElement();
	cout << "��ճɹ���" << endl;
}


int main(void) {
	
	int select = 0;
	AddressBook addressbook;
	
	while(1) {
		showMenu();
		cout << "��ѡ���ܣ�" << endl;
		cin >> select;
		
		switch(select) {
			case 1:
				addPerson(addressbook);
				break;
			case 2:
				deletePerson(addressbook); 
				break;
			case 3:
				modifyPerson(addressbook);
				break;
			case 4:
				listPerson(addressbook);
				break;
			case 5:
				clearPerson(addressbook);
				break;
			case 0:
				cout << "��ӭ�´�ʹ��" << endl;
				system("pause");
				return 0;
			default:
				continue;
		}
	}
	
	return 0;
}
