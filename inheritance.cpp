#include <iostream>
#include <string>
using namespace std;

// Base class
class Vehicle
{
  public:
    string brand = "Honda";
    Vehicle(){

    cout<<"base class constructor is called"<<endl;
    }
    void honk()
	{
      cout << "Hi, Bye! \n" ;
    }
};

// Derived class
class Car:public  Vehicle
{
  public:
    string model = "Mitsubishi";
    Car(){
    cout<<"derived class constructor is called"<<endl;
    }
};

int main()
{
    //Vehicle v1;
   // v1.honk();
    Car myCar;
    myCar.honk();
    cout << myCar.brand + " " + myCar.model;
  return 0;
}
