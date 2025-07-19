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

class WheatBasicBurger : public Burger
{
public:
    virtual void prepare()
    {
        cout << "Wheat Basic Burger Burger in 5 min" << endl;
    }
};

class WheatStandardBurger : public Burger
{
public:
    virtual void prepare()
    {
        cout << "Wheat Standard Burger Burger in 5 min" << endl;
    }
};

class WheatPremiumBurger : public Burger
{
public:
    virtual void prepare()
    {
        cout << "Wheat Premium Burger Burger in 5 min" << endl;
    }
};

class BurgerFactory
{
public:
    virtual Burger *CreateBurger(string type) = 0;
};

class SinghBuger : public BurgerFactory
{
public:
    Burger *CreateBurger(string type) override
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

class KingBuger : public BurgerFactory
{
public:
    Burger *CreateBurger(string type) override
    {
        if (type == "WheatBasic")
        {
            return new WheatBasicBurger();
        }
        else if (type == "WheatStandard")
        {
            return new WheatStandardBurger();
        }
        else if (type == "WheatPremium")
        {
            return new WheatPremiumBurger();
        }
        return nullptr;
    }
};

int main()
{
    cout << "Which Burger Shop you want :'Burgersingh' or 'Burgerking'" << endl;
    string Burger_shop;
    cin >> Burger_shop;
    if (Burger_shop == "Burgersingh")
    {
        BurgerFactory *bs = new SinghBuger();
        cout << "Welcome to Burger Singh" << endl;
        cout << "What type of Burger do you want to order?" << endl;
        while (true)
        {
            cout << "Type->'Basic' for Basic Burger, 'Standard' for Standard Burger, 'Premium' for Premium Buger,'0' to exit menu" << endl;
            string type;
            cin >> type;
            if (type == "0")
            {
                cout << "Visit again" << endl;
                break;
            }
            Burger *burger = bs->CreateBurger(type);
            if (burger)
            {
                burger->prepare();
            }
            else
            {
                cout << "Invalid" << endl;
            }
        }
    }
    else
    {
        BurgerFactory *bk = new KingBuger();
        cout << "Welcome to Burger King" << endl;
        cout << "What type of Burger do you want to order?" << endl;
        while (true)
        {
            cout << "Type->'WheatBasic' for Wheat Basic Burger, 'WheatStandard' for Wheat Standard Burger, 'WheatPremium' for Wheat Premium Buger,'0' to exit menu" << endl;
            string type;
            cin >> type;
            if (type == "0")
            {
                cout << "Visit again" << endl;
                break;
            }
            Burger *burger = bk->CreateBurger(type);
            if (burger)
            {
                burger->prepare();
            }
            else
            {
                cout << "Invalid" << endl;
            }
        }
    }
}
