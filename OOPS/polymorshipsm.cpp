// Run time polymorphism / Dynamic polymorphism / method overridding..
#include <iostream>
using namespace std;

// Base class
class Car {
public:
    virtual void accelerate() { // virtual method
        cout << "Generic car is accelerating..." << endl;
    }

    virtual ~Car() {} // Virtual destructor for safety
};

// Derived class 1
class ManualCar : public Car {
public:
    void accelerate() override {
        cout << "Manual car is accelerating by pressing clutch and gear!" << endl;
    }
};

// Derived class 2
class ElectricCar : public Car {
public:
    void accelerate() override {
        cout << "Electric car is accelerating silently with instant torque!" << endl;
    }
};

// Main function
int main() {
    Car* car1 = new ManualCar();
    Car* car2 = new ElectricCar();

    car1->accelerate();  // Calls ManualCar's accelerate()
    car2->accelerate();  // Calls ElectricCar's accelerate()

    delete car1;
    delete car2;

    return 0;
}




//static polymorphism / method overloading / compile time ploymorpism..

// #include <iostream>
// using namespace std;

// // Base class
// class Car {
//     // No need for virtual here since we are showing compile-time polymorphism
// };

// // Derived class 1
// class ManualCar {
// public:
//     void accelerate() {
//         cout << "ManualCar: Accelerating with default speed!" << endl;
//     }

//     void accelerate(int speed) {
//         cout << "ManualCar: Accelerating to " << speed << " km/h using clutch and gear." << endl;
//     }
// };

// // Derived class 2
// class ElectricCar {
// public:
//     void accelerate() {
//         cout << "ElectricCar: Smooth acceleration with default speed!" << endl;
//     }

//     void accelerate(double speed) {
//         cout << "ElectricCar: Accelerating silently to " << speed << " km/h with instant torque." << endl;
//     }
// };

// int main() {
//     ManualCar mCar;
//     ElectricCar eCar;

//     mCar.accelerate();
//     mCar.accelerate(60);     // Calls int version

//     eCar.accelerate();
//     eCar.accelerate(75.5);   // Calls double version

//     return 0;
// }

