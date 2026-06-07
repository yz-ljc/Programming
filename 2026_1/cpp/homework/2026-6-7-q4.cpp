#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    string color;
    double motopower;
    double speed;
    double weight;
    int id;

public:
    Car(string model, string color, double motopower, double speed, double weight, int id) : model(model), color(color),
        motopower(motopower),
        speed(speed), weight(weight), id(id) {
    }

    Car(const Car &car) {
        this->model = car.model;
        this->color = car.color;
        this->motopower = car.motopower;
        this->speed = car.speed;
        this->weight = car.weight;
        this->id = car.id;
    }

    void show() {
        cout << "Model: " << this->model << endl;
        cout << "Color: " << this->color << endl;
        cout << "MotoPower: " << this->motopower << endl;
        cout << "Speed: " << this->speed << endl;
        cout << "Weight: " << this->weight << endl;
        cout << "ID: " << this->id << endl;
    }
};

class Bus : public Car {
    int seats;
    int people;

public:
    Bus(string model, string color, double motopower, double speed, double weight, int id, int seats, int people)
        : Car(model, color, motopower, speed, weight, id), seats(seats), people(people) {
    }

    Bus(const Bus &bus) : Car(bus) {
        this->seats = bus.seats;
        this->people = bus.people;
    }

    void show() {
        Car::show();
        cout << "Seats: " << this->seats << endl;
        cout << "People: " << this->people << endl;
    }
};

class Truck : public Car {
    int load;
    double loaded_weight;

public:
    Truck(string model, string color, double motopower, double speed, double weight, int id, int load, double loaded_weight)
        : Car(model, color, motopower, speed, weight, id), load(load), loaded_weight(loaded_weight) {
    }

    Truck(const Truck & truck) : Car(truck) {
        this->load = truck.load;
        this->loaded_weight = truck.loaded_weight;
    }

    void show() {
        Car::show();
        cout << "Load: " << this->load << endl;
        cout << "Loaded Weight: " << this->loaded_weight << endl;
    }
};

int main() {
    Bus *bus = new Bus("Bus01", "Yellow", 150.0, 80.0, 5000.0, 1001, 40, 30);
    Truck *truck = new Truck("Truck01", "Blue", 200.0, 90.0, 8000.0, 1002, 10, 10.3);

    Bus new_bus = Bus(*bus); // 这里调拷贝构造函数好像没要求咋写，所以两种形式的各写了一个
    Truck *new_truck = new Truck(*truck);

    bus->show();
    cout << "============" << endl;
    truck->show();
    cout << "============" << endl;
    new_bus.show();
    cout << "============" << endl;
    new_truck->show();

    delete bus;
    delete truck;

    delete new_truck;
    return 0;
}
