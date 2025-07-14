#include <iostream>
#include <vector>
using namespace std;

class non_withdrawn_account
{
public:
    virtual void deposit(double amount) = 0;
};

class withdrawn_account : public non_withdrawn_account
{
public:
    virtual void withdraw(double amount) = 0;
};

class savingAccount : public withdrawn_account
{
private:
    double balance = 0;

public:
    savingAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Amount of " << amount << " is deposited current balance " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn amount " << amount << " is withdrawn cuurent balance " << balance << endl;
        }
        else
        {
            cout << "Balance if not Sufficient" << endl;
        }
    }
};
class CurrentAccount : public withdrawn_account
{
private:
    double balance = 0;

public:
    CurrentAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Amount of " << amount << " is deposited current balance " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn amount " << amount << " is withdrawn cuurent balance " << balance << endl;
        }
        else
        {
            cout << "Balance if not Sufficient" << endl;
        }
    }
};

class Fixed_deposit : public non_withdrawn_account
{
private:
    double balance = 0;

public:
    Fixed_deposit()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Amount of " << amount << " is deposited current balance " << balance << endl;
    }
};

class BankClient
{
private:
    vector<withdrawn_account *> withdrawnAccount;
    vector<non_withdrawn_account *> non_withdrawnAccount;

public:
    BankClient(vector<withdrawn_account *> withdrawaccounts,vector<non_withdrawn_account*>non_withdrawn_account)
    {
        this->withdrawnAccount = withdrawaccounts;
        this->non_withdrawnAccount=non_withdrawn_account;
    }
    void Transaction()
    {
        for (withdrawn_account *acc : withdrawnAccount)
        {
            acc->deposit(1000);
            acc->withdraw(500);
        }
        for(non_withdrawn_account *ac: non_withdrawnAccount){
            ac->deposit(500);
        }
    }
};

int main()
{
    vector<withdrawn_account *> withdrawnAccount;
    withdrawnAccount.push_back(new savingAccount());
    withdrawnAccount.push_back(new CurrentAccount());

     vector<non_withdrawn_account *> non_withdrawnAccount;
     non_withdrawnAccount.push_back(new Fixed_deposit());

    BankClient *bk = new BankClient(withdrawnAccount,non_withdrawnAccount);
    bk->Transaction();
    return 0;
}