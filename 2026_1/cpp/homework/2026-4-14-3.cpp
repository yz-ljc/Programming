#include <iostream>
#include <string>
using namespace std;

class airCondition {
    string brand;
    string color;
    int power;
    bool status;
    int temperature;

public:
    airCondition(string brand, string color, int power, int temperature, bool status = false) {
        this->brand = brand;
        this->color = color;
        this->power = power;
        this->status = status;
        this->temperature = temperature;
    }

    airCondition(const airCondition &a) : brand(a.brand), color(a.color), power(a.power), status(a.status),
                                          temperature(a.temperature) {
    }

    void change_status() {
        this->status = !this->status;
        cout << "Status: " << (status ? "ON" : "OFF") << endl;
    }

    void upper_temperature(int t) {
        this->temperature += t;
        cout << "Temperature: " << temperature << endl;
    }

    void lower_temperature(int t) {
        this->temperature -= t;
        cout << "Temperature: " << temperature << endl;
    }

    void display() {
        cout << "\n+--------------------------------------+" << endl;
        cout << "|     Air Conditioner Status       |" << endl;
        cout << "+--------------------------------------+" << endl;
        cout << "| Brand:       " << brand << endl;
        cout << "| Color:       " << color << endl;
        cout << "| Power:       " << power << " HP" << endl;
        cout << "| Status:      " << (status ? "ON" : "OFF") << endl;
        cout << "| Temperature: " << temperature << "°C" << endl;
        cout << "+--------------------------------------+" << endl;
    }
};

int main() {
    airCondition super_air_conditioner("格力", "白色", 2, 25);
    super_air_conditioner.display();

    super_air_conditioner.change_status();
    super_air_conditioner.lower_temperature(5);

    super_air_conditioner.display();

    airCondition copy_test(super_air_conditioner);

    copy_test.display();

    return 0;
}
