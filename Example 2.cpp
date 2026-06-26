#include <iostream>
using namespace std; 
class Z
{
	private:
		static int objCount;
		int num;
	public:
		Z(int a)
    	{
        	cout<<"Constructor called for object: "<<objCount<<endl;
        	num=a;
        	objCount++;
    	}
		~Z()
		{
			
			objCount--;
			cout<<"Destructor called for object: "<<objCount<<endl;
			cout<<"Value of Destroying object: "<<num<<endl;
		}    

};
int Z::objCount=1;
int main()
{
    Z z1(10); 
    cout<<"Hey "<<endl;
    int a = 1;
    if(a==1)
    {
        Z z2(20);
    }  
    cout<<"Hello World"<<endl;
} 
