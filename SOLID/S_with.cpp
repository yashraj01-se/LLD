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
    Savingto_DataBase(ShoppingCart *cart)
    {
        this->cart = cart;
    }
    void SavingTodata()
    {
        cout << "Saving to the DataBase";
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 1200));
    cart->addProduct(new Product("Mouse", 120));

    InvoicePrinter *print = new InvoicePrinter(cart);
    print->Printinfo();

    Savingto_DataBase *save = new Savingto_DataBase(cart);
    save->SavingTodata();

    return 0;
}
