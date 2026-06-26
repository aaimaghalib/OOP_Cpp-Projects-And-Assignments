#include<iostream>
using namespace std;
class a{
public:
    int pub;
protected:
    int a1;
private:
    int priv;

public:
    a(int a11){
        a1=a11;
    }
    a(){
    cout<<"Parent a"<<endl;
    }
    ~a(){
    cout<<"parent dis"<<endl;
    }
};
class b:private a{

  public:
      int var;
      b(int v, int v1):a(v1){
          var=v;
      }
      b(){cout<<"Child b"<<endl;}

    void display(){
    cout<<a1<<endl;
    cout<<var<<endl;
    cout<<pub<<endl;
  //  cout<<priv;
    }
       ~b(){
    cout<<"child dis"<<endl;
    }
};

int main(){
    b obj;
//b obj(20,10);
obj.display();
return 0;
}
