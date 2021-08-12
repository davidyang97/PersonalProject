#include <iostream>
#include "Array.hpp"
#include "Person.h"

using namespace std;

void test01() {
    Array<Person> arr(10);
    Person p1("张三", 18);
    Person p2("李四", 20);
    arr.addElement(p1);
    arr.addElement(p2);
    cout << "length: " << arr.getLength() << " size: " << arr.getSize() << endl;
    cout << arr[0].name << " " << arr[0].age << endl;
    cout << arr[1].name << " " << arr[1].age << endl;
    arr.deleteElement();
    cout << "length: " << arr.getLength() << " size: " << arr.getSize() << endl;
    cout << arr[0].name << " " << arr[0].age << endl;
    cout << arr[1].name << " " << arr[1].age << endl;
}

int main() {
    
    test01();

    return 0;
}