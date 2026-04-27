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
    void get_account() const {
        cout << "Account ID: " << id << endl;
    }
    double get_balance() const {
        return this->balance;
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
        cout << "Successfully withdrew: " << amount << " Now you have " << balance << " in total!" << endl;
    }
    Account(const Account & oop) : id(oop.id), balance(oop.balance) {}
};

class Saving {
private:
    double min_balance = 0;
    Account acc;
public:
    Saving(int id, double balance, double min_balance) : min_balance(min_balance), acc(id, balance) {}
    Saving(const Saving & saving_tmp) : min_balance(saving_tmp.min_balance), acc(saving_tmp.acc) {}

    double get_balance() const {
        return acc.get_balance();
    }

    double get_min_balance() const {
        return min_balance;
    }

    void withdraw(double amount) {
        acc.taken(amount);
    }

    void deposit(double amount) {
        acc.deposit(amount);
    }
};

int main() {
    Account acc1(10001, 520);
    Account acc2(10002, 114514);
    Account acc3(acc2);

    cout << "acc1: ";
    acc1.get_account();
    cout << "acc1 balance: " << acc1.get_balance() << endl;

    cout << "acc2: ";
    acc2.get_account();
    cout << "acc2 balance: " << acc2.get_balance() << endl;

    cout << "acc3 (copied from acc2): ";
    acc3.get_account();
    cout << "acc3 balance: " << acc3.get_balance() << endl;

    cout << "\n--- 测试存款 ---" << endl;
    acc1.deposit(100);

    cout << "\n--- 测试取款 ---" << endl;
    acc1.taken(200);
    acc1.taken(1000);

    Saving save1(20001, 5000, 1000);
    Saving save2(20002, 800, 500);
    Saving save3(save1);

    cout << "save1 - ";
    cout << "Balance: " << save1.get_balance() << ", Min Balance: " << save1.get_min_balance() << endl;

    cout << "save2 - ";
    cout << "Balance: " << save2.get_balance() << ", Min Balance: " << save2.get_min_balance() << endl;

    cout << "save3 (copied from save1) - ";
    cout << "Balance: " << save3.get_balance() << ", Min Balance: " << save3.get_min_balance() << endl;

    cout << "\n--- 测试 Saving 存款 ---" << endl;
    save1.deposit(2000);
    cout << "After deposit, save1 balance: " << save1.get_balance() << endl;

    cout << "\n--- 测试 Saving 取款 ---" << endl;
    save1.withdraw(1000);
    cout << "After withdraw, save1 balance: " << save1.get_balance() << endl;

    save1.withdraw(10000);
    cout << "After failed withdraw, save1 balance: " << save1.get_balance() << endl;

    return 0;
}