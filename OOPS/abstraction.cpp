#include <iostream>
using namespace std;
// real life car
class car
{
public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void acclerate() = 0;
    virtual void brake() = 0;
    virtual void stopingEngine() = 0;
    virtual ~car() {}; // dectructor..
};

class Sportcar : public car
{
    string brand;
    string model;
    bool isengineon;
    int currentspeed;
    int currentgear;

public:
    Sportcar(string b, string a)
    {
        brand = b;
        model = a;
        isengineon = false;
        currentspeed = 0;
        currentgear = 0; // neutral
    }

    void startEngine()
    {
        isengineon = true;
        cout << brand << model << "Engine is starting" << endl;
    }
    void shiftGear(int gear)
    {
        if (!isengineon)
        {
            cout << "Start the engine first";
            return;
        }
        currentgear = gear;
        cout << brand << model << "Shifted to gear" << currentgear << endl;
    }
    void acclerate()
    {
        if (!isengineon)
        {
            cout << "Start the engine first";
            return;
        }
        currentspeed += 20;
        cout << brand << model << "acclearting to" << currentspeed << endl;
    }
    void brake()
    {
        currentspeed -= 20;
        if (currentspeed == 0)
            currentspeed = 0;
        cout << brand << model << "Braking speed is now" << currentspeed << endl;
    }
    void stopingEngine()
    {
        isengineon = false;
        currentspeed = 0;
        currentgear = 0;
        cout << "Engine is truned off" << endl;
    }
};

int main()
{
    car *mycar = new Sportcar("Toyota", "M200");

    mycar->startEngine();
    mycar->shiftGear(1);
    mycar->acclerate();
    mycar->shiftGear(2);
    mycar->acclerate();
    mycar->shiftGear(1);
    mycar->brake();
    mycar->brake();
    mycar->stopingEngine();

    return 0;
}