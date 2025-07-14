#include <iostream>
#include <vector>
using namespace std;

class Product
{
public:
    string Name;
    double price;

    Product(string Name, double price)
    {
        this->Name = Name;
        this->price = price;
    }
};

class ShoppingCart
{

private:
    vector<Product *> products;

public:
    void addProduct(Product *p)
    {
        products.push_back(p);
    }
    const vector<Product *> &getproduct()
    {
        return products;
    }

    double calPrice()
    {
        double total = 0;
        for (auto it : products)
        {
            total += it->price;
        }
        return total;
    }
};

class InvoicePrinter
{
private:
    ShoppingCart *cart;

public:
    InvoicePrinter(ShoppingCart *cart)
    {
        this->cart = cart;
    }
    void Printinfo()
    {
        cout << "Printing the Invoice" << endl;
        for (auto it : cart->getproduct())
        {
            cout << it->Name << " -$ " << it->price << endl;
        }
        cout << "Total: $" << cart->calPrice() << endl;
    }
};

class Savingto_DataBase
{
private:
    ShoppingCart *cart;

public:
    virtual void Saving_DataBase(ShoppingCart * cart)=0;
};

class savingtoSQL: public Savingto_DataBase{
     void Saving_DataBase(ShoppingCart * cart) override{
        cout<<"Saving To SQL"<<endl;
     }
};
class savingtoMongo: public Savingto_DataBase{
     void Saving_DataBase(ShoppingCart * cart)override{
        cout<<"Saving To MongoDB"<<endl;
     }
};
class savingtoFile: public Savingto_DataBase{
     void Saving_DataBase(ShoppingCart * cart)override{
        cout<<"Saving To File"<<endl;
     }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 1200));
    cart->addProduct(new Product("Mouse", 120));

    InvoicePrinter *print = new InvoicePrinter(cart);
    print->Printinfo();

    Savingto_DataBase *save_SQL= new savingtoSQL();
    Savingto_DataBase *saving_File=new savingtoFile();
    Savingto_DataBase *saving_Mongo=new savingtoMongo();

    save_SQL->Saving_DataBase(cart);
    saving_File->Saving_DataBase(cart);
    saving_Mongo->Saving_DataBase(cart);

    return 0;
}