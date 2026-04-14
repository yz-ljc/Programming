#include <iostream>
using namespace std;

class Account {
    int id;
    double balance;
public:
    Account(int id, double balance) {
        this -> id = id;
        this -> balance = balance;
    }
    void get_account() {
        cout << "Account ID: " << id << endl;
    }
    void get_balance() {
        cout << "Account Balance: " << balance << endl;
    }
    void deposit(double amount) {
        this -> balance += amount;
        cout << "Successfully deposited: " << amount << " Now you have " << balance << " in total!" << endl;
    }
    void taken(double amount) {
        if (this ->balance - amount < 0) {
            cout << "No enough balance!" << endl;
            return;
        }
        this -> balance -= amount;
        cout << "Successfully deposited: " << amount << " Now you have " << balance << " in total!" << endl;
    }
    Account(const Account & oop) : id(oop.id), balance(oop.balance) {}
};

int main() {
    Account acc1(10001, 520);
    Account acc2(10002, 114514);
    Account acc3(acc2);

    acc1.get_account();
    acc1.get_balance();
    acc1.deposit(100);
    acc1.taken(200);

    acc2.get_account();
    acc2.get_balance();

    acc3.get_account();
    acc3.get_balance();

    return 0;
}