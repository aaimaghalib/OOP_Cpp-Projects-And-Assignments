//Why you can extend already defined array?
//Becuase it can cause change the value of an other variable
#include <iostream>
using namespace std;
int main()
{
	int a=30;
//	//print value
	cout<<"Value of a: "<<a<<endl;
//	//print address
	cout<<"Value of address: "<<&a<<endl;
	int arr[3]={1,2,3};
//	//Name of array is the address of 1st index of the array (arr[0])
	cout<<arr<<endl;
//	//print address of 0 index
//	cout<<&arr[0]<<endl;
//	//print address of 1 index
	cout<<&arr[1]<<endl;
//	//print address of 2 index
	cout<<&arr[2]<<endl;
//	//print address of 3 index 
	cout<<&arr[3]<<endl;
//	
	cout<<arr[3]<<endl;
	arr[3]=9;
	cout<<"Value of a: "<<a<<endl;
}
