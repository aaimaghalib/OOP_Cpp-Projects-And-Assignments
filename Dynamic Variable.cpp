#include<iostream>
using namespace std;
int main()
{
	int *x=new int;
	*x=5;
	cout<<x<<endl;
	cout<<*x<<endl;
	delete x;
	cout<<x<<endl;
	cout<<*x<<endl;
}
