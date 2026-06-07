#include <iostream>
#include <string>
using namespace std;

class Country {
protected:
    string name;
    string capital;
    int people_size;

public:
    Country(const string &name, const string &capital, const int people_size) {
        this->name = name;
        this->capital = capital;
        this->people_size = people_size;
    }

    void displayCountryInfo() const {
        cout << "Name: " << this->name << " Capital: " << this->capital << " People Size: " << this->people_size <<
                endl;
    }

    string getName() {
        return name;
    }

    string getCapital() {
        return capital;
    }

    int getPeopleSize() {
        return people_size;
    }
};

class Province : public Country {
    string province_capital;
    int province_people_size;

public:
    Province(const string &name, const string &capital, const int people_size, const string &province_capital,
             const int province_people_size) : Country(name, capital, people_size), province_capital(province_capital),
                                               province_people_size(province_people_size) {
    }

    void displayProvinceInfo() const {
        displayCountryInfo();
        cout << "Province Capital: " << province_capital << " Province People Size: " << province_people_size <<
                endl;
    }
};

int main() {
    Province p("China", "Beijing", 1400000000, "Guangzhou", 18000000);
    p.displayProvinceInfo();
    return 0;
}