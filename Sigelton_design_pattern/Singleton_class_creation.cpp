#include <iostream>
using namespace std;
class Singleton
{
private:
    static Singleton * instance;                        /////BUT NOT SUPPORTS MULTITHREADING////////NOT THREAD SAFE////
    Singleton() 
    {
        cout << "Object is created" << endl;
    }
public:
    static Singleton* getInstance(){
         if(instance==nullptr){
            instance=new Singleton();
         }
         return instance;
    }
};

Singleton* Singleton::instance=nullptr;

int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    if (s1 == s2)
    {
        cout << "Same objects" << endl;
    }
    else{
        cout<<"Different Objects"<<endl;
    }
}