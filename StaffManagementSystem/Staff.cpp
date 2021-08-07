#include "Staff.h"

string Staff::responsibility() {
    string result = "完成经理给的任务" << endl;
    return result;
}

string Staff::getType() {
    string result = "职员";
    return result;
}

string Staff::showInfo() {
    string result;
    result << code << " " << name << " " << age << " " << getType() << endl;
}