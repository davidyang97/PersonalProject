#include "Worker.h"

Worker::Worker(string code, string name, unsigned int age) {
    this->code = code;
    this->name = name;
    this->age = age;
    this->type = 0;
}

string Worker::showInfo() {
    string result;
    result = result + "工号：" + code + " " + "姓名：" + name + " " + "年龄：" + to_string(age) + " " + "类型：" + getType() + " " + "职责：" + responsibility() + "\n";
    return result;
}

string Worker::showRecord() {
    string result = code + " " + name + " " + to_string(age) + " " + to_string(type) + "\n";
    return result;
}