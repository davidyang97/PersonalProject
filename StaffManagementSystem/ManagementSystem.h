#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "Worker.h"
#include "Staff.h"
#include "Manager.h"
#include "Boss.h"

using namespace std;

class ManagementSystem {

public:
    ManagementSystem() {
        this->num = 0;
        readList();
    }

    void showMenu();
    void addStaff();
    void showList();
    void deleteStaff();
    void modifyStaff();
    void findStaff();
    void clearList();


private:
    map<int, Worker*, less<int>> lessList;
    map<int, Worker*, greater<int>> greaterList; 
    int num;

    void readList(); 
    void saveList();

};