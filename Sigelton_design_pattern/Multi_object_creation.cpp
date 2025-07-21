#include <iostream>
using namespace std;
class Singleton
{
public:
    Singleton()
    {
        cout << "Object is created" << endl;
    }
};
int main()
{
    Singleton *s1 = new Singleton();
    Singleton *s2 = new Singleton();

    if (s1 == s2)
    {
        cout << "Same objects" << endl;
    }
    else{
        cout<<"Different Objects"<<endl;
    }
}