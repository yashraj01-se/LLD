#include<iostream>
#include<vector>
using namespace std;

class Product{
public:
    string Name;
    double price;

    Product(string Name,double price){
        this->Name=Name;
        this->price=price;
    }
};

//class voilating S:shopping cart is holding multiple responsibility:
class ShoppingCart{

private:
    vector<Product*>products;

public:

    void addProduct(Product* p){
        products.push_back(p);
    }
    const vector<Product*> &getproduct(){
        return products;
    }

    //1.Calculate the toatal price in Cart:
    double calCarttotal(){
        double total=0;
        for(auto it:products){
            total+=it->price;
        }
        return total;
    }

    void PrintInvoice(){
        cout<<"Printing the Invoice"<<endl;
        for(auto it:products){
             cout<<it->Name <<" -$ "<<it->price<<endl;
        }
        cout<<"Total: $" <<calCarttotal()<<endl;
    }
    void DBsave(){
        cout<<"Saving to the database"<<endl;
    }

};
int main(){
    ShoppingCart* sp=new ShoppingCart();
    sp->addProduct(new Product("Laptop",1200));
    sp->addProduct(new Product("Mouse",120));
    sp->PrintInvoice();
    sp->DBsave();

    return 0;

}
