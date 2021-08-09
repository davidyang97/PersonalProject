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
        string code;
        string name;
        unsigned int age;
        unsigned int type;
        bool error = true;
        while(error) {
            cout << "���빤�ţ�" << endl;
            cin >> code;

            if(this->lessList.find(stoi(code)) != this->lessList.end()) {
                cout << "�����ظ�" << endl;
            }
            else {
                error = false;
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

        if(temp != NULL) {
            lessList[stoi(code)] = temp;
            greaterList[stoi(code)] = temp;
        }

        cout << "��ӵ�" << i + 1 << "λ�ɹ�" << endl;
    }

    this->num += n;

    saveList();

    cout << "�����ϣ�" << endl;

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
        cout << "д���ļ�ʧ��" << endl;
        return;
    }

    for(map<int, Worker*>::iterator it = this->lessList.begin(); it != this->lessList.end(); it++) {
        string temp = it->second->showRecord();
        ofs << temp;
    }
} 