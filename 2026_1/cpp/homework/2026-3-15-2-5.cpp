#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << left << setw(32) << "size of char" << right << setw(2) << sizeof(char) << " byte" << endl;
    cout << left << setw(32) << "size of unsigned char" << right << setw(2) << sizeof(unsigned char) << " byte" << endl;
    cout << left << setw(32) << "size of signed char" << right << setw(2) << sizeof(signed char) << " byte" << endl;
    cout << left << setw(32) << "size of int" << right << setw(2) << sizeof(int) << " byte" << endl;
    cout << left << setw(32) << "size of unsigned int" << right << setw(2) << sizeof(unsigned int) << " byte" << endl;
    cout << left << setw(32) << "size of signed int" << right << setw(2) << sizeof(signed int) << " byte" << endl;
    cout << left << setw(32) << "size of short int" << right << setw(2) << sizeof(short int) << " byte" << endl;
    cout << left << setw(32) << "size of unsigned short int" << right << setw(2) << sizeof(unsigned short int) << " byte" << endl;
    cout << left << setw(32) << "size of signed short int" << right << setw(2) << sizeof(signed short int) << " byte" << endl;
    cout << left << setw(32) << "size of long int" << right << setw(2) << sizeof(long int) << " byte" << endl;
    cout << left << setw(32) << "size of signed long int" << right << setw(2) << sizeof(signed long int) << " byte" << endl;
    cout << left << setw(32) << "size of long long int" << right << setw(2) << sizeof(long long int) << " byte" << endl;
    cout << left << setw(32) << "size of signed long long int" << right << setw(2) << sizeof(signed long long int) << " byte" << endl;
    cout << left << setw(32) << "size of unsigned long long int" << right << setw(2) << sizeof(unsigned long long int) << " byte" << endl;
    cout << left << setw(32) << "size of float" << right << setw(2) << sizeof(float) << " byte" << endl;
    cout << left << setw(32) << "size of double" << right << setw(2) << sizeof(double) << " byte" << endl;
    cout << left << setw(32) << "size of long double" << right << setw(2) << sizeof(long double) << " byte" << endl;
    return 0;
}