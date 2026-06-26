//Example 3: This program demonstrates the use of pointers in an array.
/*Use pointer to print the value and address of array elements*/

#include<iostream>
using namespace std;
int main ( )
{
	int arr[4] = { 5 , 10 , 15 , 20 };
	int i = 0;
	int *b;
	b = &arr[0]; /*we can also write b = arr */
	for (i=0;i<4;i++)
	{
		cout<<"value of arr "<<i<<" = "<<*b<<endl;
		cout<<"address of arr "<<i<<" = "<<b<<endl;
		b=b+1;
	}
}


