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
    { /// But breaks basic multi threading scenario:
      /// like if two threads enter the if block at same time then
        if (instance == nullptr)
        { ///...anyone of them will acquire lock and execute the object creation...
            lock_guard<mutex> lock(mtx);
            instance = new Singleton();
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