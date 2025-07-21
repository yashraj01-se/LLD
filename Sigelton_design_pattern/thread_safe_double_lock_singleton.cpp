#include <iostream>
#include <mutex>
using namespace std;
class Singleton
{
private:
    static Singleton *instance;
    static mutex mtx;

    Singleton()
    {
        cout << "Object is created" << endl;
    }

public:
    static Singleton *getInstance()
    {
        if (instance == nullptr)           // to not create lock multiple time...
        {
            lock_guard<mutex> lock(mtx);
            if (instance == nullptr)           // to not create object multiple time...
            {
                instance = new Singleton();
            }
        }
        return instance;
    }
};

Singleton *Singleton::instance = nullptr;
mutex Singleton::mtx;

int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    if (s1 == s2)
    {
        cout << "Same objects" << endl;
    }
    else
    {
        cout << "Different Objects" << endl;
    }
}