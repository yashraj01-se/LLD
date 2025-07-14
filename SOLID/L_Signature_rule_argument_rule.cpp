#include <iostream>
using namespace std;
class Animal
{
public:
    virtual void sound(string s)
    {
        cout << "Animal make " << s << " sound" << endl;
    }
};
class dog : public Animal
{
public:
    void sound(string s)
    {
        cout << "Dog make " << s << " sound" << endl;
    }
};
class client
{
private:
    Animal *ani;

public:
    client(Animal *ani)
    {
        this->ani = ani;
    }
    void makesound()
    {
        ani->sound("woff");
    }
};
int main()
{
    Animal *Iani = new Animal();
    dog *Dog = new dog();

    client *cl = new client(Dog);

    cl->makesound();
}