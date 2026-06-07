#include <iostream>
using namespace std;

class Building {
protected:
    int floors;
    int rooms;
    int area;
public:
    Building(const int floors, const int rooms, const int area) : floors(floors), rooms(rooms), area(area) {
        cout << "Construct Function of Building run." << endl;
    }

    ~Building() {
        cout << "Deconstruct Function of Building run." << endl;
    }
};

class TeacherBuilding : public Building {
    int classrooms;
public:
    TeacherBuilding(const int floors, const int rooms, const int area, const int classrooms) : Building(floors, rooms, area), classrooms(classrooms) {
        cout << "Construct Function of TeacherBuilding run." << endl;
    }

    void show() {
        cout << "Floors: " << this->floors << endl;
        cout << "Rooms: " << this->rooms << endl;
        cout << "Area: " << this->area << endl;
        cout << "Classrooms: " << this->classrooms << endl;
    }

    ~TeacherBuilding() {
        cout << "Deconstruct Function of TeacherBuilding run." << endl;
    }
};

class DormBuilding : public Building {
    int dormitories;
    int students_count;
public:
    DormBuilding(const int floors, const int rooms, const int area, const int dormitories, const int studcount)
        : Building(floors, rooms, area), dormitories(dormitories), students_count(studcount) {
        cout << "Construct Function of DormBuilding run." << endl;
    }

    void show() {
        cout << "Floors: " << this->floors << endl;
        cout << "Rooms: " << this->rooms << endl;
        cout << "Area: " << this->area << endl;
        cout << "Dormitories: " << this->dormitories << endl;
        cout << "Student Count: " << this->students_count << endl;
    }

    ~DormBuilding() {
        cout << "Deconstruct Function of DormBuilding run." << endl;
    }
};

int main() {
    TeacherBuilding tb(5, 50, 2000, 20);
    DormBuilding db(6, 120, 3000, 60, 480);

    cout << "=== TeacherBuilding ===" << endl;
    tb.show();

    cout << "=== DormBuilding ===" << endl;
    db.show();

    return 0;
}