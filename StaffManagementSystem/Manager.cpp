#include "Manager.h"

string Manager::responsibility() {
    string result = "根据老板给的任务下发任务给普通员工，并进行跟进\n";
    return result;
}

string Manager::getType() {
    string result = "经理";
    return result;
}
