#include <iostream>
using namespace std;
class Animal
{
};
class Dog : public Animal
{
};

class Parent
{
public:
    virtual Animal *getinstace()
    {
        cout << "Animal instance" << endl;
        return new Animal();
    }
};
class child : public Parent
{
public:
    Dog *getinstace()
    {
        cout << "Dog instance" << endl;
        return new Dog();
    }
};
class client{
private:
    Parent* p;
public:
    client(Parent * p){
     this->p=p;
    }
    void check_instance(){
        p->getinstace();
    }

};
int main(){
    Parent * p=new Parent();
    child * ch=new child();


    client *cl=new client(p);
    p->getinstace();
}
