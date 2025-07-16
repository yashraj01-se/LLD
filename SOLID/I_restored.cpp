#include<iostream>
using namespace std;
class twoDshape
{
public:
    virtual double area() = 0;
};
class threeDshape{
    public:
    virtual double area()=0;
    virtual double volume() = 0;
};

class square: public twoDshape{
  private:
    double side;

public:
   square(double side): side(side){}
    double area() override
    {
        return side * side;
    }
        
};


class rectangle : public twoDshape
{

private:
    double length,breadth;

public:
   rectangle(double length, double breadth): length(length),breadth(breadth){}
    double area() override
    {
        return 2*(length+breadth);
    }

};


class cube : public threeDshape
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
    twoDshape* sh=new rectangle(12,3);
    double area=sh->area();
    cout<<"Area of rectangle : "<<area<<endl;

    threeDshape* tw=new cube(12);
    double volume=tw->volume();
    cout<<"Volume of Cude : "<<volume<<endl;
}
