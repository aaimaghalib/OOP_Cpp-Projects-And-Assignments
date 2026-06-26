#include <iostream>
using namespace std;
void centimize(double& ptrd)
{
	cout<<&ptrd<<endl;
	ptrd *= 2.54;
}
int main()
{
	double var = 10.0; //var has value of 10 inches
	cout<<&var<<endl;
	cout << "var = " << var << " inches" << endl;
	centimize(var); //change var to centimeters
	cout << "var = " << var << " centimeters" << endl;
	return 0;
}
