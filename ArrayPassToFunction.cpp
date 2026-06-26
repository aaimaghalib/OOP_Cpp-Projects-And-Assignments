#include <iostream>
using namespace std;
//Formal parameters as a refrence 
double getAverage(int arr[], int size) 
{
	
	int i, sum = 0;       
	double avg;          
	for (i = 0; i < size; ++i) 
	{
    	sum += arr[i];
	}
   avg = double(sum) / size;
//   arr[0]=9;
    return avg;
}

int main () {
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;
//   cout<<"Value on 0 index: "<<balance[0]<<endl;
   avg = getAverage( balance, 5 ) ; 
   cout << "Average value is: " << avg << endl; 
//   cout<<"Value on 0 index: "<<balance[0];
   return 0;
}

