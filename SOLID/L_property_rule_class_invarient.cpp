#include<iostream>
using namespace std;
class Account{
    public:
       double balance;
    public:
        Account(double b){
            if(balance<0)throw invalid_argument("Balance cannot be negative");
            else{
                balance=b;
            }
        }
        virtual void withdraw(double amount){
                if(balance<amount){
                    throw runtime_error("insufficient Balance");
                }
                else{
                    balance-=amount;
                    cout<<"Amount of : "<<amount<<" is deducted current balance "<<balance<<endl;
                }
        }
};
class Cheataccount:public Account{
    public:
       Cheataccount(double b):Account(b){};
        void withdraw(double amount) override{
            balance-=amount;
            cout<<"Amount of : "<<amount<<" is deducted current balance "<<balance<<endl;
        }

};
int main(){
    Account* ac=new Cheataccount(100);
    ac->withdraw(200);
    ac->withdraw(200);
}