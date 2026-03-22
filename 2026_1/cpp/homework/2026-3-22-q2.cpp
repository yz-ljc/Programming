#include <iostream>
#include <string>
using namespace std;

void type_1() {
    int index = 1;
    for (int i = 1;i <= 9;i++) {
        cout << " " << index;
        for (int j = 1;j <=9;j++) {
            cout << "\t" << i * j;
        }
        index++;
        cout << "\n";
    }
}

void type_2() {
    int index = 1;
    for (int i = 1;i <= 9;i++) {
        cout << " " << index;
        for (int j = 1;j <=i;j++) {
            cout << "\t" << i * j;
        }
        index++;
        cout << "\n";
    }
}

void type_3() {
    int index = 1;
    for (int i = 1;i <= 9;i++) {
        cout << " " << index;
        for (int j = 1;j <=9;j++) {
            if (i > j) {
                cout << "\t";
                continue;
            }
            cout << "\t" << i * j;
        }
        index++;
        cout << "\n";
    }
}

int main() {
    int type;
    cout << "Input the type you want:" << endl;
    cin >> type;
    for (int i = 1;i <= 9;i++) {
        if (i == 1) cout << " *";
        cout << "\t" << i;
    }
    cout << endl;
    for (int i = 0;i < 78;i++) {
        cout << "-";
    }
    cout << endl;
    switch (type) {
        case 1 : type_1(); break;
        case 2 : type_2(); break;
        case 3 : type_3(); break;
        default: type_1(); break;
    }
    return 0;
}