#include <iostream>
#include<mutex>
using namespace std;
class Singleton
{
private:
    static Singleton * instance;  
    static mutex mtx;   

    Singleton() 
    {
        cout << "Object is created" << endl;
    }
public:
    static Singleton* getInstance(){
        lock_guard<mutex> lock(mtx);          /// BUT STILL ITS NOT COMPUTATIONALLY EFFICIENT ///
         if(instance==nullptr){
            instance=new Singleton();
         }
         return instance;
    }
};

Singleton* Singleton::instance=nullptr;
mutex Singleton::mtx;

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