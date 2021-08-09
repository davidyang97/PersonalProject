#include "Worker.h"

Worker::Worker(string code, string name, unsigned int age) {
    this->code = code;
    this->name = name;
    this->age = age;
    this->type = 0;
}

string Worker::showInfo() {
    string result;
    result = result + "���ţ�" + code + " " + "������" + name + " " + "���䣺" + to_string(age) + " " + "���ͣ�" + getType() + " " + "ְ��" + responsibility() + "\n";
    return result;
}

string Worker::showRecord() {
    string result = code + " " + name + " " + to_string(age) + " " + to_string(type) + "\n";
    return result;
}