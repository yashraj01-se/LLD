#include<iostream>
using namespace std;
class car{
    public:
    int speed=0;
    public:
       car(int s){
             this->speed=s;
       }
       void accelarate(int s){
            speed+=s;
            cout<<"Speed is increased by "<<s<<" current speed : "<<speed<<endl;
       }
       void brake(int s){
        speed-=s;
        cout<<"Speed is decreased by "<<s<<" current speed : "<<speed<<endl;
       }
};
class hybridcar: public car{
    public:
      hybridcar(int s): car (s){
        this->speed=s;
      }
      int charge=0;
       void brake(int s){
        speed-=s;
        charge+=10;
        cout<<"Speed is decreased by "<<s<<" current speed : "<<speed<<endl;
       }
};
int main(){
    car* hy=new car(20);
    hy->accelarate(100);
    hy->brake(100);

}
