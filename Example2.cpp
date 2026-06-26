#include<iostream>
using namespace std;
int main ( ) 
{
	int a = 5,b=6;
	int *a1,*b1;
	a1 = &a;
	b1=&b;
	int c;
	c=*a1+b;
	cout<<c;
	
}

