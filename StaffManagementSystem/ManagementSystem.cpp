#include "ManagementSystem.h"

void ManagementSystem::showMenu() {
    while(1) {
        system("cls");
        cout << "***************职工管理系统**************" << endl;
        cout << "**********    0. 退出管理程序  *********" << endl;
        cout << "**********    1. 增加职工信息  *********" << endl;
        cout << "**********    2. 显示职工信息  *********" << endl;
        cout << "**********    3. 删除离职职工  *********" << endl;
        cout << "**********    4. 修改职工信息  *********" << endl;
        cout << "**********    5. 查找职工信息  *********" << endl;
        cout << "**********    6. 清空所有文档  *********" << endl;
        cout << "***************************************" << endl;

        cout << "您的选择是：" << endl;
        int select;
        cin >> select;
        switch(select) {
            case 0:
                cout << "欢迎下次使用！" << endl;
                exit(0);
            case 1:
                addStaff();
                break;
            case 2:
                showList();
                break;
            case 3:
                deleteStaff();
                break;
            case 4:
                modifyStaff();
                break;
            case 5:
                findStaff();
                break;
            case 6:
                clearList();
                break;
            default:
                cout << "输入错误" << endl;
                continue;
        }
    }
}

void ManagementSystem::showList() {
    readList();

    if(this->lessList.empty() || this->greaterList.empty()) {
        cout << "记录为空" << endl;
        system("pause");
        return;
    }

    cout << "请输入 1-顺序 2-逆序" << endl;
    int chosen;
    cin >> chosen;

    if(chosen == 1) {
        
        for(map<int, Worker*>::iterator it = this->lessList.begin(); it != this->lessList.end(); it++) {
            cout << it->second->showInfo();
        }
        cout << "\n一共" << this->num << "条记录\n";
        system("pause");
    }
    else if(chosen == 2) {
        for(map<int, Worker*>::iterator it = this->greaterList.begin(); it != this->greaterList.end(); it++) {
            cout << it->second->showInfo();
        }
        cout << "\n一共" << this->num << "条记录\n";
        system("pause");
    }
    else {
        cout << "输入错误！" << endl;
    }
}

void ManagementSystem::addStaff() {
    cout << "请输入要添加的员工数量：" << endl;
    int n;
    cin >> n;
    if(n <= 0)  {
        cout << "输入错误" << endl;
        return;
    }

    for(int i = 0; i < n; i++) {
        string code;
        string name;
        unsigned int age;
        unsigned int type;
        bool error = true;
        while(error) {
            cout << "输入工号：" << endl;
            cin >> code;

            if(this->lessList.find(stoi(code)) != this->lessList.end()) {
                cout << "工号重复" << endl;
            }
            else {
                error = false;
            }
        }
        
        cout << "输入姓名：" << endl;
        cin >> name;
        cout << "输入年龄：" << endl;
        cin >> age;

        error = true;
        while(error) {
            cout << "输入类型(1-职员 2-经理 3-老板)：" << endl;
            cin >> type;
            if(type < 1 || type > 3) {
                cout << "输入错误" << endl;
            }
            else {
                error = false;
            }
        }
        
        Worker *temp = NULL;
        switch(type) {
            case 1:
                temp = new Staff(code, name, age);
                break;
            case 2:
                temp = new Manager(code, name, age);
                break;
            case 3:
                temp = new Boss(code, name, age);
                break;
            default:
                cout << "type error: " << type << endl;
        }

        if(temp != NULL) {
            lessList[stoi(code)] = temp;
            greaterList[stoi(code)] = temp;
        }

        cout << "添加第" << i + 1 << "位成功" << endl;
    }

    this->num += n;

    saveList();

    cout << "添加完毕！" << endl;

    system("pause");
}

void ManagementSystem::deleteStaff() {

}

void ManagementSystem::modifyStaff() {

}

void ManagementSystem::findStaff() {

}

void ManagementSystem::clearList() {

}


void ManagementSystem::readList() {
    ifstream ifs("list.txt", ios::in);
    if(!ifs.is_open()) {
        return;
    }
    string code;
    string name;
    unsigned int age;
    unsigned int type;

    int n = 0;
    while(ifs >> code && ifs >> name && ifs >> age && ifs >> type) {
        n++;
    }
    this->num = n;

    ifs.close();
    ifs.open("list.txt", ios::in);
    if(!ifs.is_open()) {
        return;
    }

    for(int i = 0; i < n; i++) {
        if(ifs >> code && ifs >> name && ifs >> age && ifs >> type) {
            Worker *temp = NULL;
            switch(type) {
                case 1:
                    temp = new Staff(code, name, age);
                    break;
                case 2:
                    temp = new Manager(code, name, age);
                    break;
                case 3:
                    temp = new Boss(code, name, age);
                    break;
                default:
                    cout << "type error: " << type << endl;
            }
            
            if(temp != NULL) {
                lessList[stoi(code)] = temp;
                greaterList[stoi(code)] = temp;
            }
        }
        else {
            break;
        }
    }
}

void ManagementSystem::saveList() {
    ofstream ofs("list.txt", ios::out);
    if(!ofs.is_open()) {
        cout << "写入文件失败" << endl;
        return;
    }

    for(map<int, Worker*>::iterator it = this->lessList.begin(); it != this->lessList.end(); it++) {
        string temp = it->second->showRecord();
        ofs << temp;
    }
} 