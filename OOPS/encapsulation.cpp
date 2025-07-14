#include <iostream>
using namespace std;

class Sportcar 
{
private:
    //charactreristics--
    string brand;
    string model;
    bool isengineon;
    int currentspeed;
    int currentgear;
    string tyre;

public:
    Sportcar(string b, string a)
    {
        brand = b;
        model = a;
        isengineon = false;
        currentspeed = 0;
        currentgear = 0; // neutral
        tyre="mrf";
    }

    //getters and setters:
    int getcurrentspeed(){
        return this->currentspeed;
    }

    string gettyre(){
         return tyre;
    }
    void settyre(string tyre){
    //can put some validation...
     this->tyre=tyre;
    }

    //behaviours--
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

int main(){

    Sportcar *mycar = new Sportcar("Toyota", "M200");

    mycar->startEngine();
    mycar->shiftGear(1);
    mycar->acclerate();
    mycar->shiftGear(2);
    mycar->acclerate();
    mycar->shiftGear(1);
    mycar->brake();
    mycar->brake();
    mycar->stopingEngine();

    mycar->settyre("volvo");
    string tyre=mycar->gettyre();
    cout<<tyre;
    
}