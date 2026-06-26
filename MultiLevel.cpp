#include<iostream>
using namespace std;

class grandparent
{
 protected:
     int no_of_shops;
     int no_of_houses;

 public:
    grandparent()
    {
        no_of_shops=2;
        no_of_houses=1;

    }

    void manage_shops()
     {
         cout<<"Shop management done"<<endl;
     }
     void totalProperty()
     {
         cout<<"Grandfather Total Property"<<endl;
     }

};

class parent:public grandparent
{
protected:
    int no_of_cars;

public:
    parent()
    {
        no_of_cars=2;

    }

    void drive_car()
    {
        cout<<"Driving Car"<<endl;
    }

    void inherited_grandparent()
    {

        cout<<"Inherited Grandparent"<<endl;
        cout<<"No of Shops "<<no_of_shops<<endl;
        cout<<"No of Houses "<<no_of_houses<<endl;
    }
     void totalProperty()
     {
         cout<<"Father Total Property"<<endl;
     }



};

class child:public parent
{
private:

    string status;
public:
    child()
    {

        status="Student";
    }
    void play()
    {
        cout<<"Playing PUBG"<<endl;
    }

    void study()
    {
        cout<<"Study in BSCS"<<endl;
    }

    void inherited_parent()
    {
        cout<<"Inherited Parent"<<endl;
        cout<<"No of shops "<<no_of_shops<<endl;
        cout<<"No of Houses "<<no_of_houses<<endl;
        cout<<"No of cars "<<no_of_cars<<endl;
    }
      void totalProperty()
     {
         cout<<"Grandfather Total Property"<<endl;
     }

};

int main()
{

child obj;
obj.manage_shops();
obj.drive_car();
obj.play();
obj.study();
obj.inherited_grandparent();
obj.inherited_parent();
obj.totalProperty();

return 0;
}
