#include <iostream>
using namespace std;
class Singleton
{
private:
    Singleton()
    {
        cout << "Object is created" << endl;
    }
public:
    static Singleton* getInstance(){
         return new Singleton();
    }
};
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