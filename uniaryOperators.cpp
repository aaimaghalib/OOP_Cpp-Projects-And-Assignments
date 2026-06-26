#include<iostream>
using namespace std;

class demo
{
    int num;
    float numfloat;
public:
    demo(int n, float f)
    {
        num=n;
        numfloat=f;

    }
    void show()
    {

        cout<<num<<"  "<<numfloat<<endl;

    }

    void operator ++()
    {
        ++num;
        ++numfloat;
    }

    void operator ++(int)
    {
        num++;
        numfloat++;
    }

    void operator --()
    {
        --num;
        --numfloat;
    }
    void operator --(int)
    {
        num--;
        numfloat--;
    }
};


int main()
{

demo obj(10, 15.6);
obj.show();
++obj;
obj.show();
obj++;
obj.show();
--obj;
obj.show();
obj--;
obj.show();



return 0;
}
