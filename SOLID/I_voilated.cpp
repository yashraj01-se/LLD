#include <iostream>
using namespace std;
class shape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class square : public shape
{

private:
    double side;

public:
   square(double side): side(side){}
    double area() override
    {
        return side * side;
    }
    double volume()override{
        throw logic_error("Volume cannot be calculated");
    }
};

class rectangle : public shape
{

private:
    double length,breadth;

public:
   rectangle(double length, double breadth): length(length),breadth(breadth){}
    double area() override
    {
        return 2*(length+breadth);
    }
    double volume()override{
        throw logic_error("Volume cannot be calculated");
    }
};

class cube : public shape
{

private:
    double side;

public:
   cube(double side): side(side){}
    double area() override
    {
        return side * side;
    }
    double volume()override{
        return side*side*side;
    }
};

int main(){
    shape* sh=new rectangle(12,3);
    double area=sh->area();
    cout<<area<<endl;
    sh->volume();
}