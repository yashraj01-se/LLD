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
class fixed_account:public Account{
    public:
       fixed_account(double b):Account(b){};
       //broke the history constraint led us to beaking of LSP rule... 
        void withdraw(double amount) override{
           throw runtime_error("Withdrawal not allowed");
        }

};
int main(){
    Account* ac=new fixed_account(100);
    ac->withdraw(200);
    ac->withdraw(200);
}