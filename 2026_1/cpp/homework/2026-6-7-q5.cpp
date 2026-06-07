#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    static int construct_times;
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
        cout << "Construct Car for " << ++construct_times << endl;
    }

    Car(const Car &car) {
        this->model = car.model;
        this->color = car.color;
        this->motopower = car.motopower;
        this->speed = car.speed;
        this->weight = car.weight;
        this->id = car.id;
    }

    virtual void show() {
        cout << "Model: " << this->model << endl;
        cout << "Color: " << this->color << endl;
        cout << "MotoPower: " << this->motopower << endl;
        cout << "Speed: " << this->speed << endl;
        cout << "Weight: " << this->weight << endl;
        cout << "ID: " << this->id << endl;
    }

    virtual ~Car() {
        cout << "Virtual Destruct Function Car." << endl;
    }
};

int Car::construct_times = 0;

class Bus : virtual public Car {
protected:
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

class Truck : virtual public Car {
protected:
    int load;
    double loaded_weight;

public:
    Truck(string model, string color, double motopower, double speed, double weight, int id, int load,
          double loaded_weight)
        : Car(model, color, motopower, speed, weight, id), load(load), loaded_weight(loaded_weight) {
    }

    Truck(const Truck &truck) : Car(truck) {
        this->load = truck.load;
        this->loaded_weight = truck.loaded_weight;
    }

    void show() {
        Car::show();
        cout << "Load: " << this->load << endl;
        cout << "Loaded Weight: " << this->loaded_weight << endl;
    }
};

class BusAndTruck : public Bus, public Truck {
public:
    BusAndTruck(string model, string color, double motopower, double speed,
                double weight, int id, int seats, int people, int load, double loaded_weight) : Car(model, color,
            motopower, speed, weight, id),
        Bus(model, color, motopower, speed, weight, id, seats, people),
        Truck(model, color, motopower, speed, weight, id, load, loaded_weight) {
    }

    BusAndTruck(const BusAndTruck & bus_and_truck) : Car(bus_and_truck), Bus(bus_and_truck), Truck(bus_and_truck) {
    }

    void show() {
        Car::show();
        cout << "Seats: " << this->seats << endl;
        cout << "People: " << this->people << endl;
        cout << "Load: " << this->load << endl;
        cout << "Loaded Weight: " << this->loaded_weight << endl;
    }
};

int main() {
    BusAndTruck *bat = new BusAndTruck("BAT2024", "Black", 250.0, 120.0, 9000.0, 8888, 45, 38, 20, 15.6);

    bat->Bus::show();
    cout << "======================" << endl;
    bat->Truck::show();
    cout << "======================" << endl;
    bat->show();
    cout << "======================" << endl;

    BusAndTruck *bat1 = new BusAndTruck("Atri", "Colored", 280.0, 150.0,8500.0, 9527, 50, 42, 15, 12.3);

    bat1->show();
    cout << "======================" << endl;

    delete bat;
    delete bat1;
    return 0;
}
