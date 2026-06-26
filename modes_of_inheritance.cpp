// C++ Implementation to show that a derived class
// doesn’t inherit access to private data members.
// However, it does inherit a full parent object.
#include<iostream>
using namespace std;

class A {
public:
	int x;
	void honk();

protected:
	int y;

private:
	int z;
};

void A::honk()
	{
    cout<<"Base Class function called"<<endl;
    }


class B : public A {
	// x is public
	// y is protected
	// z is not accessible from B
public:
    void display_B()
    {
        cout<<"Function B:"<<endl;
        cout<<"X is Public so value of X is "<<x<<endl;
        cout<<"Y is Protected so value of Y is "<<y<<endl;
    }

};

class C : protected A {
	// x is protected
	// y is protected
	// z is not accessible from C

};

class D : private A // 'private' is default for classes
{
	// x is private
	// y is private
	// z is not accessible from D

};

int main()
{

    B obj;
    obj.honk();
    obj.display_B();



}

