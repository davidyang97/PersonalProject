#include "Staff.h"

string Staff::responsibility() {
    string result = "��ɾ����������\n";
    return result;
}

string Staff::getType() {
    string result = "ְԱ";
    return result;
}

string Staff::showInfo() {
    string result = code + " " + name + " " + to_string(age) + " " + getType() + "\n";
    return result;
}