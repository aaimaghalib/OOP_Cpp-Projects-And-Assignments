#include<iostream>
using namespace std;

class demo
{


    int num1, num2;
public:
    demo(int n1, int n2)
    {

        num1=n1;
        num2=n2;
    }

    void show()
    {
        cout<<num1<<"  "<<num2<<endl;
    }




    demo operator +(demo &obj)
    {
        demo temp(0,0);
        temp.num1=num1+obj.num1;
        temp.num2=num2+obj.num2;

        return temp;

    }
};


int main()
{

demo obj(0,0), obj1(10, 20), obj2(20,40), obj3(10,5);
obj=obj1+obj2+obj3;
obj.show();


return 0;
}
