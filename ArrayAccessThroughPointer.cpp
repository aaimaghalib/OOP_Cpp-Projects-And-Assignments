#include <iostream>
using namespace std;
int main()
{ 
	int intarray[5] = { 31, 54, 77, 52, 93 };
	cout<<intarray<<endl;//address of 0 index
//	cout<<*intarray;//value of 0 index
	for(int j=0; j<5; j++) //for each element,
		cout << *(intarray+j) << endl; //print value
	return 0;
}
