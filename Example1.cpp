/*Example 1: This program demonstrates pointer to integers, 
pointer to float and pointer to character data types.*/

#include<iostream>
using namespace std;
int main ( ) 
{
	char a = 'b';
	char *a1;
	
	int b = 5;
	int *b1;
	
	float c = 5.5;
	float *c1;
	
	a1 = &a;
	b1 = &b;
	c1 = &c;
	
	cout<<"value of a = "<<a<<endl;
	cout<<"value of a = "<<*(&a)<<endl;
	cout<<"value of a = "<<*a1<<endl;
	
	cout<<"value of b = "<<b<<endl;
	cout<<"value of b = "<<*(&b)<<endl;
	cout<<"value of b = "<<*b1<<endl;

	cout<<"value of c = "<<c<<endl;
	cout<<"value of c = "<<*(&c)<<endl;
	cout<<"value of c = "<<*c1<<endl;
	
	cout<<"address of a = "<<a1<<endl;
	cout<<"address of b = "<<b1<<endl;
	cout<<"address of c = "<<c1<<endl;
}

