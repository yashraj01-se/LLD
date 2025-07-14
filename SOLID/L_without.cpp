#include<iostream>
#include<vector>
using namespace std;

class account{
    public:
    virtual void deposit(double account)=0;
    virtual void withdraw(double account)=0;
};

class savingAccount: public account{
private:
   double balance=0;
public:
    savingAccount(){
        balance=0;
    }

    void deposit(double amount){
        balance+=amount;
        cout<<"Amount of "<<amount<<" is deposited current balance "<<balance<<endl;
    }

    void withdraw(double amount){
        if(balance>=amount){
          balance-=amount;
          cout<<"Withdrawn amount "<<amount<<" is withdrawn cuurent balance "<<balance<<endl;
        }
        else{
            cout<<"Balance if not Sufficient"<<endl;
        }
    }
};

class currentAccount: public account{
private:
   double balance=0;
public:
    currentAccount(){
        balance=0;
    }

    void deposit(double amount){
        balance+=amount;
        cout<<"Amount of "<<amount<<" is deposited current balance "<<balance<<endl;
    }

    void withdraw(double amount){
        if(balance>=amount){
          balance-=amount;
          cout<<"Withdrawn amount "<<amount<<" is withdrawn cuurent balance "<<balance<<endl;
        }
        else{
            cout<<"Balance if not Sufficient"<<endl;
        }
    }
};

class fixedDeposit: public account{
private:
   double balance=0;
public:
    fixedDeposit(){
        balance=0;
    }

    void deposit(double amount){
        balance+=amount;
        cout<<"Amount of "<<amount<<" is deposited current balance "<<balance<<endl;
    }

    void withdraw(double amount){
       throw logic_error("Withdrawn is not possible");
    }
};

class BankClient{
private:
    vector<account*>accounts;
public:
    BankClient(vector<account*>accounts){
        this->accounts=accounts;
    }
    void Transaction(){
        for (account* acc: accounts){
            acc->deposit(1000);
            try
            {
                acc->withdraw(500);
            }
            catch(const logic_error& e)
            {
                cout<<"error: "<<e.what()<<endl;
            }
            
        }
        
    }
};

int main(){
    vector<account*>account;
    account.push_back(new savingAccount());
    account.push_back(new currentAccount());
    account.push_back(new fixedDeposit());

    BankClient* bk=new BankClient(account);
    bk->Transaction();
    return 0;
   

}