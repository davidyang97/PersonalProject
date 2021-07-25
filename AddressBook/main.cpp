#include <iostream>
#include "person.h"
#include "addressbook.h"

using namespace std;

void showMenu() {
	cout << endl << "*********通讯录管理系统*********" << endl;
	cout << "*******   1. 添加联系人  *******" << endl;
	cout << "*******   2. 删除联系人  *******" << endl;
	cout << "*******   3. 修改联系人  *******" << endl;
	cout << "*******   4. 显示联系人  *******" << endl;
	cout << "*******   5. 查找联系人  *******" << endl;
	cout << "*******   6. 清空联系人  *******" << endl;
	cout << "*******   0. 退出        *******" << endl;
	cout << "********************************" << endl << endl;
}

void addPerson(AddressBook &addressbook) {
	string name;
	cout << "请输入名字：" << endl;
	cin >> name;
	int age;
	cout << "请输入年龄：" << endl;
	cin >> age;
	int sex = 0;
	while(sex != 1 && sex != 2) {
		cout << "请输入性别 1-男 2-女：" << endl;
		cin >> sex;
	}
	string address;
	cout << "请输入地址：" << endl;
	cin >> address;
	string phone;
	cout << "请输入电话号码：" << endl;
	cin >> phone;
	
	Person person(name, age, sex, address, phone);
	if(!addressbook.addElement(person)) {
		cout << "已有此联系人！" << endl;
	}
	else {
		cout << "添加成功！" << endl;
	} 
}

void deletePerson(AddressBook &addressbook) {
	string name;
	cout << "请输入名字：" << endl;
	cin >> name;
	if(!addressbook.deleteElement(name)) {
		cout << "未查到此联系人！" << endl;
	}
	else {
		cout << "删除成功！" << endl;
	} 
}

void modifyPerson(AddressBook &addressbook) {
	string name;
	cout << "请输入名字：" << endl;
	cin >> name;
	int age;
	cout << "请输入年龄：" << endl;
	cin >> age;
	int sex = 0;
	while(sex != 1 && sex != 2) {
		cout << "请输入性别 1-男 2-女：" << endl;
		cin >> sex;
	}
	string address;
	cout << "请输入地址：" << endl;
	cin >> address;
	string phone;
	cout << "请输入电话号码：" << endl;
	cin >> phone;
	
	Person person(name, age, sex, address, phone);
	
	if(!addressbook.modifyElement(person)) {
		cout << "未查到此联系人！" << endl;
	}
	else {
		cout << "修改成功！" << endl;
	} 
}

void listPerson(AddressBook &addressbook) {
	vector<Person> list = addressbook.listElement();
	
	cout << "联系人列表如下：" << endl; 
	int i = 0;
	for(auto it = list.begin(); it != list.end(); it++) {
		int sex = it->sex;
		string temp;
		if(sex == 1) temp = "男";
		else temp = "女";
		cout << it->name << "\t" << it->age << "\t" << temp << "\t" << it->address << "\t" << it->phone << endl;
		i++;
	}
	cout << "显示完毕，一共" << i << "条记录" << endl; 
}

void findPerson(AddressBook &addressbook)  {
	string name;
	cout << "请输入名字：" << endl;
	cin >> name;
	Person person = addressbook.findElement(name);
	if(person.name.empty()) {
		cout << "查无此人！" << endl;
	}
	else {
		string temp;
		if(person.sex == 1) temp = "男";
		else temp = "女";
		cout << "联系人信息如下：" << endl;
		cout << person.name << "\t" << person.age << "\t" << temp << "\t" << person.address << "\t" << person.phone << endl;
	}
}

void clearPerson(AddressBook &addressbook) {
	addressbook.clearElement();
	cout << "清空成功！" << endl;
}


int main(void) {
	
	int select = 0;
	AddressBook addressbook;
	
	while(1) {
		showMenu();
		cout << "请选择功能：" << endl;
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
				findPerson(addressbook);
				break;
			case 6:
				clearPerson(addressbook);
				break;
			case 0:
				cout << "欢迎下次使用" << endl;
				system("pause");
				return 0;
			default:
				continue;
		}
	}
	
	return 0;
}
