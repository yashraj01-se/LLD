#include <iostream>
using namespace std;

// Base class
class Car {
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

public:
    Car(string b, string m) {
        brand = b;
        model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << " engine started." << endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        cout << brand << " " << model << " engine stopped." << endl;
    }

    void accelerate() {
        if (!isEngineOn) {
            cout << "Start the engine first!" << endl;
            return;
        }
        currentSpeed += 10;
        cout << brand << " " << model << " accelerated to " << currentSpeed << " km/h." << endl;
    }

    void brake() {
        currentSpeed -= 10;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " slowed down to " << currentSpeed << " km/h." << endl;
    }
};

// Derived class
class SportCar : public Car {
public:
    SportCar(string b, string m) : Car(b, m) {}

    void turboBoost() {
        if (!isEngineOn) {
            cout << "Start the engine to use turbo!" << endl;
            return;
        }
        currentSpeed += 50;
        cout << brand << " " << model << " activated TURBO! Speed: " << currentSpeed << " km/h." << endl;
    }
};

int main() {
    SportCar myCar("Lamborghini", "Huracan");

    myCar.startEngine();
    myCar.accelerate();
    myCar.turboBoost();
    myCar.brake();
    myCar.stopEngine();

    return 0;
}
