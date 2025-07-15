#include<iostream>
using namespace std;
class user{
    public :
       virtual void createPassword(string password){
           if(password.length()>8){
                cout<<"password id Strong";
           }
           else{
               throw invalid_argument("Pasword is waek");
           }
       }
};
class Admin: public user{
    public:
    void createPassword(string password){
        if(password.length()>6){
            cout<<"password id strong";
        }
        else{
            throw invalid_argument("Password is wek");
        }
    }
};
int main(){
    user *u=new user();
    u->createPassword("Yashraj");
}