//Multiple Inheritance with Diamond Problem
#include<iostream>
using namespace std;
class Person
{
// Data members of person
int a;
public:
	Person()
	{
		cout << "Person::Person(default) 	called" << endl;
	}
	Person(int x)
	{
	a=x;
//	cout<<a;
	cout << "Person::Person(int ) 	called " <<endl;
	}
	void print()
	{
		cout<<"Person Class "<<a;
	}
};
class Father :  public Person
{
public:
	Father()
	{
		cout<<"Father::Father(default) 	called"<< endl;
	}
	Father(int x):Person(x)
	{
		cout<<"Father::Father(int )	called"<< endl;
	}
	void print()
	{
		cout<<"Father Class";
	}
};
class Mother : public Person
{
// data members of Mother
public:
	Mother()
	{
		cout<<"Mother::Mother(default)  called"<< endl;
	}
	Mother(int x):Person(x)
	{
	cout<<"Mother::Mother(int ) 	called"<< endl;
	}
	void print()
	{
		cout<<"Mother Class"<<endl;
	}
};
class Child : public Father, public Mother
{
public:
	Child()
	{
		cout<<"Child::Child called"<< endl;
	}
//	Child(int x):Mother (x),Father(x) //see End
//	{
//		cout<<"Child::Child(int ) called"<< endl;
//	}
	Child(int x):Mother (x),Father(x)//see End
	{
	cout<<"Child::Child(int ) called"<< endl;
	}
	void print()
	{
		cout<<"Child Class"<<endl;
	}
};
//
int main()
{
//	Child c;
//	c.print();
//	c.Mother::print();
//	c.Person::print();
	Child Child1(30);
	Child1.print();
	//Child1.Person::print(); //As function is overriding, it will gives error when we will not use "virtual" keyword
}

/* when we did not use "virtual" keyword, and want to run parameterized constructor of Class person then we can write
Child(int x):Mother (x),Father(x)
But in case of using virtual keyword to avoid dimond problem will use
Child(int x):Mother (x),Father(x),Person(x)
Reson is this
To prevent the constructor from running multiple times,
the constructor for a virtual base class/es is not called by the class inheriting from it.
Instead, the constructor is called by the constructor of the concrete class.
if you need to execute the parameterized constructor of the base class,
You can do so by explicitly calling it in the Child class rather than
the Father or Mother classes.
But if you write
Child(int x):Mother (x),Father(x)
with "virtual" keyword then there you must made a default consturctor */
