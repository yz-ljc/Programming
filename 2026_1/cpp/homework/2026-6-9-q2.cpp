#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    long uin;
    string name;
    double money;
public:
    Employee(long uin, string name) {
        this->uin = uin;
        this->name = name;
        this->money = 0;
    }

    virtual void setSalary(double money) = 0;

    void display() const {
        cout << "=========================" << endl;
        cout << "Uin: " << this->uin << endl;
        cout << "Name: " << this->name << endl;
        cout << "Salary: " << this->money << endl;
        cout << "=========================" << endl;
    }

    virtual ~Employee() {}
};

class Manager : public Employee {
public:
    Manager(long uin, string name) : Employee(uin, name) {}

    void setSalary(double money) override {
        this->money = 8000;
    }
};

class Technician : public Employee {
public:
    Technician(long uin, string name) : Employee(uin, name) {}

    void setSalary(double worktime) override {
        this->money = 20 * worktime;
    }
};

class SaleMan : public Employee {
public:
    SaleMan(long uin, string name) : Employee(uin, name) {}

    void setSalary(double monthlyPerformance) override {
        this->money = monthlyPerformance * 0.004;
    }
};

class SalesManager : public Employee {
public:
    SalesManager(long uin, string name) : Employee(uin, name) {}

    void setSalary(double earnedMoney) override {
        this->money = 5000 + earnedMoney * 0.005;
    }
};

int main() {
    const int SIZE = 4;
    Employee* employees[SIZE];

    for (int i = 0; i < SIZE; i++) {
        long uin;
        string name;
        int type;
        double data;

        cout << "请输入员工编号: ";
        cin >> uin;
        cout << "请输入员工姓名: ";
        cin >> name;
        cout << "类型 (1=经理,2=技术员,3=销售员,4=销售经理): ";
        cin >> type;

        switch(type) {
            case 1:
                employees[i] = new Manager(uin, name);
                employees[i]->setSalary(0);
                break;
            case 2:
                employees[i] = new Technician(uin, name);
                cout << "请输入工作时间(小时): ";
                cin >> data;
                employees[i]->setSalary(data);
                break;
            case 3:
                employees[i] = new SaleMan(uin, name);
                cout << "请输入月销售额: ";
                cin >> data;
                employees[i]->setSalary(data);
                break;
            case 4:
                employees[i] = new SalesManager(uin, name);
                cout << "请输入部门月销售额: ";
                cin >> data;
                employees[i]->setSalary(data);
                break;
        }
    }

    for (Employee* & employee : employees) {
        employee->display();
        delete employee;
    }

    return 0;
}