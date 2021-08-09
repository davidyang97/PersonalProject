#include "ManagementSystem.h"

void ManagementSystem::showMenu() {
    while(1) {
        system("cls");
        cout << "***************ְ������ϵͳ**************" << endl;
        cout << "**********    0. �˳��������  *********" << endl;
        cout << "**********    1. ����ְ����Ϣ  *********" << endl;
        cout << "**********    2. ��ʾְ����Ϣ  *********" << endl;
        cout << "**********    3. ɾ����ְְ��  *********" << endl;
        cout << "**********    4. �޸�ְ����Ϣ  *********" << endl;
        cout << "**********    5. ����ְ����Ϣ  *********" << endl;
        cout << "**********    6. ��������ĵ�  *********" << endl;
        cout << "***************************************" << endl;

        cout << "����ѡ���ǣ�" << endl;
        int select;
        cin >> select;
        switch(select) {
            case 0:
                cout << "��ӭ�´�ʹ�ã�" << endl;
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
                cout << "�������" << endl;
                continue;
        }
    }
}

void ManagementSystem::showList() {
    readList();

    if(this->lessList.empty() || this->greaterList.empty()) {
        cout << "��¼Ϊ��" << endl;
        system("pause");
        return;
    }

    cout << "������ 1-˳�� 2-����" << endl;
    int chosen;
    cin >> chosen;

    if(chosen == 1) {
        
        for(map<int, Worker*>::iterator it = this->lessList.begin(); it != this->lessList.end(); it++) {
            cout << it->second->showInfo();
        }
        cout << "\nһ��" << this->num << "����¼\n";
        system("pause");
    }
    else if(chosen == 2) {
        for(map<int, Worker*>::iterator it = this->greaterList.begin(); it != this->greaterList.end(); it++) {
            cout << it->second->showInfo();
        }
        cout << "\nһ��" << this->num << "����¼\n";
        system("pause");
    }
    else {
        cout << "�������" << endl;
    }
}

void ManagementSystem::addStaff() {
    cout << "������Ҫ��ӵ�Ա��������" << endl;
    int n;
    cin >> n;
    if(n <= 0)  {
        cout << "�������" << endl;
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

        cout << "��ӵ�" << i + 1 << "λ�ɹ�" << endl;
    }

    this->num += n;

    saveList();

    cout << "�����ϣ�" << endl;

    system("pause");
}

void ManagementSystem::deleteStaff() {
    Worker* worker = findOne();

    if(worker == NULL) {
        cout << "���޴���" << endl;
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
        cout << "ɾ���ɹ�" << endl;
    }

    system("pause");
}

void ManagementSystem::modifyStaff() {
    Worker* worker = findOne();

    if(worker == NULL) {
        cout << "���޴���" << endl;
    }
    else {
        bool con = true;
        while(con) {
            cout << "��ǰ������ϢΪ��" << endl << worker->showInfo();
            cout << "������Ҫ�޸ĵ��� 1-���� 2-���� 3-����" << endl;
            int select;
            cin >> select;
            if(select < 1 || select > 3) {
                cout << "�������" << endl;
            }
            else {
                switch(select) {
                    case 1:
                    {
                        cout << "����������" << endl;
                        string name;
                        cin >> name;
                        worker->name = name;
                        break;
                    }
                    case 2:
                    {
                        cout << "�������䣺" << endl;
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
                            cout << "��������(1-ְԱ 2-���� 3-�ϰ�)��" << endl;
                            cin >> type;
                            if(type < 1 || type > 3) {
                                cout << "�������" << endl;
                            }
                            else {
                                error = false;
                            }
                        }
                        worker->type = type;
                        break;
                    }
                }

                cout << "�޸ĳɹ� 1-�����޸Ĵ�����Ϣ ����-���� " << endl;
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
        cout << "���޴���" << endl;
    }
    else {
        cout << worker->showInfo();
    }
    system("pause");
}

void ManagementSystem::clearList() {
    cout << "��ȷ���Ƿ�Ҫ����������� 0-���� 1-ȷ��" << endl;
    int select;
    cin >> select;
    if(select != 0 && select != 1) {
        cout << "�������" << endl;
    }
    else {
        this->lessList.erase(this->lessList.begin(), this->lessList.end());
        this->greaterList.erase(this->greaterList.begin(), this->greaterList.end());
        this->nameList.erase(this->nameList.begin(), this->nameList.end());
        saveList();
        cout << "������" << endl;
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
    	            cout << "����: " + code + " ��ʽ����" << endl;
	            }
                catch(std::out_of_range&) {
                    cout << "����: " + code + " ������Χ" << endl;
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
        cout << "д���ļ�ʧ��" << endl;
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
        cout << "��ѡ�� 1-���� 2-����" << endl;
        cin >> select;
        if(select != 1 && select != 2) {
            cout << "�������" << endl;
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
        cout << "���빤�ţ�" << endl;
        cin >> code;
        try {
            i_code = stoi(code);
            worker = this->findCode(i_code);
        } 
        catch(std::invalid_argument&) {
            cout << "����: " + code + " ��ʽ����" << endl;
        }
        catch(std::out_of_range&) {
            cout << "����: " + code + " ������Χ" << endl;
        }
    }
    else {
        cout << "����������" << endl;
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
        cout << "���빤�ţ�" << endl;
        cin >> code;
        try {
            int i_code = stoi(code);
            if(this->lessList.find(i_code) != this->lessList.end()) {
                cout << "�����ظ�" << endl;
            }
            else {
                error = false;
            }
        } 
        catch(std::invalid_argument&) {
            cout << "����: " + code + " ��ʽ����" << endl;
        }
        catch(std::out_of_range&) {
            cout << "����: " + code + " ������Χ" << endl;
        }
                
    }
    
    cout << "����������" << endl;
    cin >> name;
    cout << "�������䣺" << endl;
    cin >> age;

    error = true;
    while(error) {
        cout << "��������(1-ְԱ 2-���� 3-�ϰ�)��" << endl;
        cin >> type;
        if(type < 1 || type > 3) {
            cout << "�������" << endl;
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