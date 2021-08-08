#include <string>
#include <iostream>
#include <cstdlib>
#include "Worker.h"
#include "Staff.h"

using namespace std;

int main() {
    string code = "0123";
    string name = "ÕÅÈý";

    Staff *worker = new Staff(code, name, 22);

    string temp = worker->responsibility();
    cout << temp;
    system("pause");
    return 0;
}