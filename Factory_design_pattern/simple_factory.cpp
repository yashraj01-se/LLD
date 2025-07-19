#include <iostream>
using namespace std;
class Burger
{
public:
    virtual void prepare() = 0;
};

class BasicBurger : public Burger
{
public:
    virtual void prepare()
    {
        cout << "Basic Burger in 5 min" << endl;
    }
};

class StandardBurger : public Burger
{
public:
    virtual void prepare()
    {
        cout << "Standard Burger in 5 min" << endl;
    }
};

class PremiumBurger : public Burger
{
public:
    virtual void prepare()
    {
        cout << "Premium Burger in 5 min" << endl;
    }
};

class BurgerFactory{
public:
    Burger* CreateBurger(string type)
    {
        if (type == "Basic")
        {
            return new BasicBurger();
        }
        else if (type == "Standard")
        {
            return new StandardBurger();
        }
        else if (type == "Premium")
        {
            return new PremiumBurger();
        }
        return nullptr;
    }
};

int main()
{
    BurgerFactory *bf=new BurgerFactory();
    cout << "Welcome to BurgerMania" << endl;
    cout << "What type of Burger do you want to order?" << endl;
    while (true)
    {
        cout << "Menu : 'Basic Burger, Standard Burger, Premium Burger'" << endl;
        cout << "Type->'Basic' for Basic Burger, 'Standard' for Standard Burger, 'Premium' for Premium Buger,'0' to exit menu" << endl;
        string type;
        cin >> type;
        if(type=="0"){
            cout<<"Visit again"<<endl;
            break;
        }
        
        Burger * burger=bf->CreateBurger(type);
        if(burger){
            burger->prepare();
        }
        else{
            cout<<"Invalid"<<endl;
        }
    }
}
