#include <iostream>
#include "Array.hpp"
#include "Person.h"

using namespace std;

void test00() {
    cout << "test00" << endl;
    Array<int> arr1(10);
    for(int i = 0; i < 10; i++) {
        arr1.addElement(i);
    }

    cout << arr1.addElement(3) << endl;

    cout << "arr2: " << endl;
    Array<int> arr2(arr1);
    for(int i = 0; i < 10; i++) {
        cout << arr2[i] << endl;
    }

    cout << "arr3: " << endl;
    Array<int> arr3(100);
    arr3 = arr1;
    for(int i = 0; i < 10; i++) {
        cout << arr3[i] << endl;
    }

    cout << "arr3.length: " << arr3.getLength() << endl;

    for(int i = 0; i < 11; i++) {
        cout << "delete: " << arr3.deleteElement() << endl;
        cout << "data: " << arr3[arr3.getSize() - 1] << endl;
    }
}

void test01() {
    cout << "test01" << endl;
    Array<Person> arr(3);
    Person p1("张三", 18);
    Person p2("李四", 20);
    Person p3("王五", 22);
    Person p4("天天", 24);
    cout << "arr1----------" << endl;
    cout << arr.addElement(p1) << endl;
    cout << arr.addElement(p2) << endl;
    cout << arr.addElement(p3) << endl;
    cout << arr.addElement(p4) << endl;
    cout << "length: " << arr.getLength() << " size: " << arr.getSize() << endl;
    cout << arr[0].name << " " << arr[0].age << endl;
    cout << arr[1].name << " " << arr[1].age << endl;
    cout << arr[2].name << " " << arr[2].age << endl;
    cout << arr[3].name << " " << arr[3].age << endl;
    arr.deleteElement();
    cout << "length: " << arr.getLength() << " size: " << arr.getSize() << endl;
    cout << arr[1].name << " " << arr[1].age << endl;
    cout << arr[2].name << " " << arr[2].age << endl;

    cout << "arr2----------" << endl;
    Array<Person> arr2(arr);
    cout << arr2[0].name << " " << arr2[0].age << endl;
    cout << arr2[1].name << " " << arr2[1].age << endl;

    cout << "arr3----------" << endl;
    Array<Person> arr3(100);
    cout << arr3.addElement(p4) << endl;
    cout << arr3.addElement(p3) << endl;
    cout << arr3.addElement(p2) << endl;
    cout << arr3.addElement(p1) << endl;
    arr3 = arr2;
    cout << arr3[0].name << " " << arr2[0].age << endl;
    cout << arr3[1].name << " " << arr2[1].age << endl;
}

int main() {
    
    test00();
    test01();

    return 0;
}