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
        
        Worker* temp = this->addOne();
        if(temp != NULL) {
            int i_code = stoi(temp->code);
            lessList[i_code] = temp;
            greaterList[i_code] = temp;
            nameList[temp->name] = temp;
        }

        cout << "添加第" << i + 1 << "位成功" << endl;
    }

    this->num += n;

    saveList();

    cout << "添加完毕！" << endl;

    system("pause");
}

void ManagementSystem::deleteStaff() {
    Worker* worker = findOne();

    if(worker == NULL) {
        cout << "查无此人" << endl;
    }
    else {
        string name = worker->name;
        int i_code = stoi(worker->code);
        delete worker;
        this->lessList.erase(i_code);
        this->greaterList.erase(i_code);
        this->nameList.erase(name);
        this->num--;
        saveList();
        cout << "删除成功" << endl;
    }

    system("pause");
}

void ManagementSystem::modifyStaff() {
    Worker* worker = findOne();

    if(worker == NULL) {
        cout << "查无此人" << endl;
    }
    else {
        bool con = true;
        while(con) {
            cout << "当前此人信息为：" << endl << worker->showInfo();
            cout << "请输入要修改的列 1-姓名 2-年龄 3-类型" << endl;
            int select;
            cin >> select;
            if(select < 1 || select > 3) {
                cout << "输入错误" << endl;
            }
            else {
                switch(select) {
                    case 1:
                    {
                        cout << "输入姓名：" << endl;
                        string name;
                        cin >> name;
                        worker->name = name;
                        break;
                    }
                    case 2:
                    {
                        cout << "输入年龄：" << endl;
                        int age;
                        cin >> age;
                        worker->age = age;
                        break;
                    }
                    case 3:
                    {
                        bool error = true;
                        int type = 0;
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
                        worker->type = type;
                        break;
                    }
                }

                cout << "修改成功 1-继续修改此人信息 其余-返回 " << endl;
                cin >> select;
                if(select == 1) {
                    con = true;
                }
                else {
                    con = false;
                }
            }
        }
    }
}

void ManagementSystem::findStaff() {
    Worker* worker = findOne();

    if(worker == NULL) {
        cout << "查无此人" << endl;
    }
    else {
        cout << worker->showInfo();
    }
    system("pause");
}

void ManagementSystem::clearList() {
    cout << "请确认是否要清空所有数据 0-返回 1-确认" << endl;
    int select;
    cin >> select;
    if(select != 0 && select != 1) {
        cout << "输入错误" << endl;
    }
    else {
        this->lessList.erase(this->lessList.begin(), this->lessList.end());
        this->greaterList.erase(this->greaterList.begin(), this->greaterList.end());
        this->nameList.erase(this->nameList.begin(), this->nameList.end());
        saveList();
        cout << "清空完毕" << endl;
    }

    system("pause");
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
                try {
                    int i_code = stoi(code);
                    lessList[i_code] = temp;
                    greaterList[i_code] = temp;
                    nameList[name] = temp;
                } 
                catch(std::invalid_argument&) {
    	            cout << "工号: " + code + " 格式错误" << endl;
	            }
                catch(std::out_of_range&) {
                    cout << "工号: " + code + " 超出范围" << endl;
                }
            }
        }
        else {
            break;
        }
    }
    ifs.close();
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
    ofs.close();
} 

Worker* ManagementSystem::findCode(int code) {
    map<int, Worker*>::iterator it = this->lessList.find(code);
    if(it == this->lessList.end()) {
        return NULL;
    }
    else {
        return it->second;
    }
}

Worker* ManagementSystem::findName(string name) {
    map<string, Worker*>::iterator it = this->nameList.find(name);
    if(it == this->nameList.end()) {
        return NULL;
    }
    else {
        return it->second;
    }
}

Worker* ManagementSystem::findOne() {
    bool error = true;
    int select;
    while(error) {
        cout << "请选择 1-工号 2-姓名" << endl;
        cin >> select;
        if(select != 1 && select != 2) {
            cout << "输入错误" << endl;
        }
        else {
            error = false;
        }
    }

    string code;
    int i_code;
    Worker* worker = NULL;
    string name;

    if(select == 1) {
        cout << "输入工号：" << endl;
        cin >> code;
        try {
            i_code = stoi(code);
            worker = this->findCode(i_code);
        } 
        catch(std::invalid_argument&) {
            cout << "工号: " + code + " 格式错误" << endl;
        }
        catch(std::out_of_range&) {
            cout << "工号: " + code + " 超出范围" << endl;
        }
    }
    else {
        cout << "输入姓名：" << endl;
        cin >> name;
        worker = this->findName(name);
    }

    return worker;
}

Worker* ManagementSystem::addOne() {
    string code;
    string name;
    unsigned int age;
    unsigned int type;
    bool error = true;
    while(error) {
        cout << "输入工号：" << endl;
        cin >> code;
        try {
            int i_code = stoi(code);
            if(this->lessList.find(i_code) != this->lessList.end()) {
                cout << "工号重复" << endl;
            }
            else {
                error = false;
            }
        } 
        catch(std::invalid_argument&) {
            cout << "工号: " + code + " 格式错误" << endl;
        }
        catch(std::out_of_range&) {
            cout << "工号: " + code + " 超出范围" << endl;
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

    return temp;
}