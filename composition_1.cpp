// composition
#include <iostream>
using namespace std;
class Engine 
{
public:
  void start()  {}
  void rev()  {}
  void stop()  {}
};

class Wheel 
{
public:
  void inflate(int psi)  {
  cout<<"\npsi: "<<psi;}
};

class Window 
{
public:
  void rollup()  {
  cout<<"I am rolling up";}
  void rolldown()  {}
};

class Door 
{
public:
  Window window;
  void open()  {}
  void close()  {}
};
//
class Car 
{
public:
  Engine engine;
  Wheel wheel[4];
  Door left, right; // 2-door
};
//
int main() 
{
  Car car;
  car.left.window.rollup();
  car.wheel[0].inflate(72);
}
