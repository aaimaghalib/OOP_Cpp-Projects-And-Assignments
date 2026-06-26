#include <iostream>
using namespace std;
void foo(int *arr,int s)
{
	for(int i=0;i<s;i++)
	{
		cout<<*(arr+i)<<endl;
	}
}
int main()
{ 
	int intarray[5] = { 31, 54, 77, 52, 93 };
	int size = sizeof(intarray)/sizeof(intarray[0]);
	foo(intarray,size);
	return 0;
}
