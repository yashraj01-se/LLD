#include <iostream>
using namespace std;
class parent
{
public:
    virtual void getvalue() noexcept(false)
    {
        throw logic_error("Logical error");
    }
};

class child : public parent
{
public:
    void getvalue() noexcept(false)
    {
        throw underflow_error("Out of range error");  // this exception(subclass) is of different parent hence code toh fata....
    }
};

class client
{
private:
    parent *p;

public:
    client(parent *p)
    {
        this->p = p;
    }
    void geterror()
    {
        try
        {
            p->getvalue();
        }
        catch (const logic_error &e)
        {
            cout << e.what() << '\n';
        }
    }
};
int main(){
    parent *p=new parent();
    child *ch=new child();

    client *cl=new client(ch);
    cl->geterror();

}