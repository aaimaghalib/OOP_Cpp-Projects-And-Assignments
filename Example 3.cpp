#include<iostream>
using namespace std;
class base
{
	public:
		base()
		{
			cout<<"Base Class Constructor"<<endl;	
		}
		~base()
		{
			cout<<"Base Class Distructor"<<endl;	
		}	
};
class child:public base
{
	public:
		child()
		{
			cout<<"child Class Constructor"<<endl;	
		}	
		~child()
		{
			cout<<"child Class Distructor"<<endl;	
		}	
};

int main()
{
	cout<<"\nStrart\n";
	{
		child c1;
	}
	cout<<"Hello world";
}
