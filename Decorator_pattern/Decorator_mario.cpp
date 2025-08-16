#include <vector>
#include <iostream>
using namespace std;

// Abstract Character Class:
class Character
{
public:
    virtual string get_abilities() = 0;
};

// Concrete Character Class:
class Mario : public Character
{
public:
    string get_abilities()
    {
        return "Mario";
    }
};

// Abstract Decorator: Decorator "is a" Character:
class Decorator : public Character
{
public:
    Character *C;

public:
    Decorator(Character *c)
    {
        this->C = c;
    }
};

// Concrete Decorator: Decorator "has a" Character:
class heightup : public Decorator
{

public:
    heightup(Character *c) : Decorator(c) {} // We are initializing the base Decorator with the Character object that we want to wrap.
    string get_abilities()
    {
        return C->get_abilities() + " Height up";
    }
};

class GunPower : public Decorator
{
public:
    GunPower(Character *c) : Decorator(c) {}

    string get_abilities()
    {
        return C->get_abilities() + " with Gun";
    }
};

class StarPower : public Decorator
{

public:
    StarPower(Character *c) : Decorator(c) {}

    string get_abilities(){
        return C->get_abilities()+" with star Power";
    }
};

int main(){
    Character * mario=new Mario();
    cout<<"Starting:"<<mario->get_abilities()<<endl;

    mario= new heightup(mario);
    cout<<mario->get_abilities()<<endl;

    mario=new GunPower(mario);
    cout<<mario->get_abilities()<<endl;

    mario=new StarPower(mario);
    cout<<mario->get_abilities()<<endl;

    delete mario;
    return 0;

}
