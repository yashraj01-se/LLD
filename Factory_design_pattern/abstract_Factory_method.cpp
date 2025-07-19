#include <iostream>
using namespace std;

// Product Burger....

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

// Product Bread;
class Bread
{
public:
    virtual void CBread() = 0;
};

class BasicwheatBread : public Bread
{
public:
    virtual void CBread()
    {
        cout << "Basic Wheat Bread in 10 minutes" << endl;
    }
};

class StandardwheatBread : public Bread
{
public:
    virtual void CBread()
    {
        cout << "Standard Wheat Bread in 10 minutes" << endl;
    }
};

class PremiumwheatBread : public Bread
{
public:
    virtual void CBread()
    {
        cout << "Premium Wheat Bread in 10 minutes" << endl;
    }
};

class BasicGarlicBread : public Bread
{
public:
    virtual void CBread()
    {
        cout << "Basic Garlic Bread in 10 minutes" << endl;
    }
};

class StandardGarlicBread : public Bread
{
public:
    virtual void CBread()
    {
        cout << "Standard Garlic Bread in 10 minutes" << endl;
    }
};

class PremiumGarlicBread : public Bread
{
public:
    virtual void CBread()
    {
        cout << "Premium Garlic Bread in 10 minutes" << endl;
    }
};

class BurgerFactory
{
public:
    virtual Burger *CreateBurger(string type) = 0;
    virtual Bread *CreateBread(string type) = 0;
};

class SinghBuger : public BurgerFactory
{
public:
    Burger *CreateBurger(string type) override
    {
        if (type == "BasicBurger")
        {
            return new BasicBurger();
        }
        else if (type == "StandardBurger")
        {
            return new StandardBurger();
        }
        else if (type == "PremiumBurger")
        {
            return new PremiumBurger();
        }
        return nullptr;
    }

    Bread *CreateBread(string type) override
    {
        if (type == "BasicwheatBread")
        {
            return new BasicwheatBread();
        }
        else if (type == "StandardwheatBread")
        {
            return new StandardwheatBread();
        }
        else if (type == "wheatPremiumBread")
        {
            return new PremiumwheatBread();
        }
        return nullptr;
    }
};

class KingBuger : public BurgerFactory
{
public:
    Burger *CreateBurger(string type) override
    {
        if (type == "WheatBasicBurger")
        {
            return new WheatBasicBurger();
        }
        else if (type == "WheatStandardBurger")
        {
            return new WheatStandardBurger();
        }
        else if (type == "WheatPremiumBurger")
        {
            return new WheatPremiumBurger();
        }
        return nullptr;
    }

    Bread *CreateBread(string type) override
    {
        if (type == "BasicGarlicBread")
        {
            return new BasicGarlicBread();
        }
        else if (type == "StandardGarlicBread")
        {
            return new StandardGarlicBread();
        }
        else if (type == "PremiumGarlicBread")
        {
            return new PremiumGarlicBread();
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
        while (true)
        {
            cout << "What do you want 'Burger' or 'Bread'" << endl;
            string food;
            cin >> food;
            if (food == "Burger")
            {
                cout << "What type of Burger do you want to order?" << endl;
                cout << "Type->'BasicBurger' for Basic Burger, 'StandardBurger' for Standard Burger, 'PremiumBuger' for Premium Buger,'0' to exit menu" << endl;
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
            if (food == "Bread")
            {
                cout << "What type of Bread do you want to order?" << endl;
                cout << "Type->'BasicwheatBread' for Basic wheat Bread, 'StandardwheatBread' for Standard wheat Bread, 'wheatPremiumBread' for Premium wheat Braed,'0' to exit menu" << endl;
                string type;
                cin >> type;
                if (type == "0")
                {
                    cout << "Visit again" << endl;
                    break;
                }
                Bread *bread = bs->CreateBread(type);
                if (bread)
                {
                    bread->CBread();
                }
                else
                {
                    cout << "Invalid" << endl;
                }
            }
        }
    }
    else
    {
        BurgerFactory *bk = new KingBuger();
        cout << "Welcome to Burger King" << endl;

        while (true)
        {
            cout << "What do you want 'Burger' or 'Bread'" << endl;
            string food;
            cin >> food;
            if (food == "Burger")
            {
                cout << "What type of Burger do you want to order?" << endl;
                cout << "Type->'WheatBasicBurger' for Wheat Basic Burger, 'WheatStandardBurger' for Wheat Standard Burger, 'WheatPremiumBurger' for Wheat Premium Buger,'0' to exit menu" << endl;
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
            if (food == "Bread")
            {
                cout << "What type of Bread do you want to order?" << endl;
                cout << "Type->'BasicGarlicBread' for Garlic Basic Burger, 'StandardGarlicBread' for Garlic Standard Burger, 'PremiumGarlicBread' for Garlic Premium Buger,'0' to exit menu" << endl;
                string type;
                cin >> type;
                if (type == "0")
                {
                    cout << "Visit again" << endl;
                    break;
                }
                Bread *bread = bk->CreateBread(type);
                if (bread)
                {
                    bread->CBread();
                }
                else
                {
                    cout << "Invalid" << endl;
                }
            }
        }
    }
}
