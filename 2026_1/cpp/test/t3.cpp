#include <iostream>

using namespace std;

class A {

private:

    int value;

    static int svalue;

public:

    A(int n) { value = n; }

    static void sfun(A &r);

    void fun() { cout << value << endl; }

}; 

//start

int A::svalue = 10;

void A::sfun(A &r)

{

    r.value += 20;

    svalue += 20; 

    r.fun();

    cout << svalue << endl;

} 

//end

int main()
{

    int n; 

    cin >> n;

    A a(n);

    A::sfun(a);

    return 0; 

}