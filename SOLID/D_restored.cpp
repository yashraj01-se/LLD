#include<iostream>
using namespace std;

class persistence{
public:
   virtual void save(int data)=0;
};

class SQLdb: public persistence{
    public:
        void save(int data)override{
            cout<<"Saving to SQL : "<<data<<endl;
        }
};

class Mongodb: public persistence{
    public:
        void save(int data)override{
            cout<<"Saving to SQL : "<<data<<endl;
        }
};

class application{
    public:
       persistence* p;  // dependency injection - when we pass an object as a variable in different class
    public:
       application(persistence* p){
        this->p=p;
       }
       void save(int data){
           p->save(data);
       }
};

int main(){
    application  a=new SQLdb();
    a.save(2);
}
