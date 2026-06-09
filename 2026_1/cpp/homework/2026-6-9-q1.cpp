#include <iostream>
#include <string>
using namespace std;

class Base {
protected:
    string bookName;
public:
    Base() {
        this->bookName = "Unknown";
    }

    Base(string name) {
        this->bookName = name;
    }

    void setTitle(string name) {
        this->bookName = name;
    }

    void showTitle() {
        cout << "Book Name: " << this->bookName << endl;
    }

    virtual bool isGood() = 0;

    virtual ~Base() {}
};

class Book : public Base {
    int soldAmount;
public:
    Book() : Base() {
        this->soldAmount = 0;
    }

    Book(string name, int soldAmount) : Base(name) {
        this->soldAmount = soldAmount;
    }

    bool isGood() {
        return soldAmount > 500;
    }
};

class Journal : public Base {
    int soldAmount;
public:
    Journal() : Base() {
        this->soldAmount = 0;
    }

    Journal(string name, int soldAmount) : Base(name) {
        this->soldAmount = soldAmount;
    }

    bool isGood() {
        return soldAmount > 2500;
    }
};

int main() {
    int n;
    cout << "请输入物品数量: ";
    cin >> n;

    Base** items = new Base*[n];

    for (int i = 0; i < n; i++) {
        string name;
        int type, sales;

        cout << "\n请输入名称: ";
        cin >> name;
        cout << "类型 (1=图书, 2=杂志): ";
        cin >> type;
        cout << "请输入月销量: ";
        cin >> sales;

        if (type == 1) {
            items[i] = new Book(name, sales);
        } else {
            items[i] = new Journal(name, sales);
        }
    }

    cout << "\n===== 销售情况分析 =====" << endl;
    for (int i = 0; i < n; i++) {
        items[i]->showTitle();
        cout << (items[i]->isGood() ? "Good" : "Not good") << endl;
        delete items[i];
    }

    delete[] items;

    return 0;
}