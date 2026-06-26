//aggregation
#include<iostream>
 using namespace std;
 class Address
 {
 	int houseNo;
     public:  
	 Address(){}      
         string colony,city, state;
         Address(int hno, string Colony, string City, string State)
 {
         houseNo = hno;
         colony=Colony;
         city = City;
         state = State;
   }
   int getHouseNo()
   {
   	return houseNo;
   }
 };
 class Person
 {
     private:
     	string name;
         Address address;
     public:
         Person(string Name, Address Add)
 {
         name = Name;
         address = Add;
     }
 void display()
 {
     cout<< name<< " "<< " "<< address.getHouseNo()<<" "<<address.colony<<" " <<address.city<< " "<<address.state<<endl;
 }
 };
 int main()
 {
 Address add1(63 ,"Edan Abad","Lahore","Pakistan");
 Person p1 ("Ahsan: ",add1);
 Person p2 ("Ahmad: ",add1);
 p1.display();
 p2.display();
 }
