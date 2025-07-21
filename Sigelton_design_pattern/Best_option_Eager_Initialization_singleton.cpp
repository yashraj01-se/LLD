#include<iostream>
using namespace std;
class Singleton{
private:
     static Singleton* instance;
    
     Singleton(){
        cout<<"Object Created"<<endl;
     }
public:
     static Singleton* getinstance(){
        return instance;
     }
};

Singleton* Singleton::instance=new Singleton();

int main(){
    Singleton * s1=Singleton::getinstance();
    Singleton * s2=Singleton::getinstance();

      if (s1 == s2)
    {
        cout << "Same objects" << endl;
    }
    else{
        cout<<"Different Objects"<<endl;
    }
}