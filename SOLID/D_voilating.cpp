#include<iostream>
using namespace std;
class SQL{
    public:
    void savetoSQL(int data){
        cout<<"saving to SQL Database: "<<data<<endl;;
    }
};
class Mongo{
    public:
     void savetoMongo(int data){
        cout<<"saving to Mongo: "<<data<<endl;
     }
};
class application{
    public:
       SQL s;
       Mongo m;
    public:
        void savetoSQL(int data){
            s.savetoSQL(data);
        }
        void savetoMongo(int data){
            m.savetoMongo(data);
        }
};

int main(){
    application * a=new application();
    a->savetoSQL(2);
    a->savetoMongo(2);

}