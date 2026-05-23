#include <iostream>
using namespace std;

class BBank;
class GBank;
class CBank {
    int balance;
public:
    CBank() {
        this->balance = 0;
    }

    CBank(const int balance) : balance(balance) {
    }

    void setBalance(int balance) {
        this->balance = balance;
        cout << "CBank Current Balance: " << this->balance << endl;
    }

    friend int total(CBank &c, BBank &b, GBank &g);
};

class BBank {
    int balance;
public:
    BBank() {
        this->balance = 0;
    }

    BBank(const int balance) : balance(balance) {
    }

    void setBalance(int balance) {
        this->balance = balance;
        cout << "BBank Current Balance: " << this->balance << endl;
    }

    friend int total(CBank &c, BBank &b, GBank &g);
};

class GBank {
    int balance;
public:
    GBank() {
        this->balance = 0;
    }

    GBank(const int balance) : balance(balance) {
    }

    void setBalance(int balance) {
        this->balance = balance;
        cout << "GBank Current Balance: " << this->balance << endl;
    }

    friend int total(CBank &c, BBank &b, GBank &g);
};

int total(CBank &c, BBank &b, GBank &g) {
    return c.balance + b.balance + g.balance;
}

int main() {
    CBank c_account(1000);
    BBank b_account;
    GBank g_account(3200);

    c_account.setBalance(8888);
    b_account.setBalance(3333);
    g_account.setBalance(0);

    cout << "Your current total balance: " << total(c_account, b_account, g_account) << endl;

    return 0;
}