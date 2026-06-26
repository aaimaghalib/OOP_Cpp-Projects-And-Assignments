#include<iostream>
using namespace std;

class mother
{
    protected:
    string eye_color;
    string complexion;

    public:
        mother()
        {
            eye_color="green";
            complexion="White";

        }
    void talktive()
    {
        cout<<"Speaks Alot"<<endl;
    }
    void expert_cook()
    {
        cout<<"Cooks delicious"<<endl;
    }
    void singing()
    {
        cout<<"Mother sings well"<<endl;
    }



};

class father
{
protected:
    float height;
public:
    father()
    {
        height=5.9;

    }

    void manager()
    {
        cout<<"Good managing skills"<<endl;
    }
     void singing()
    {
        cout<<"Father sings well"<<endl;
    }


};

class child:public mother,public father
{
public:
     void singing()
    {
        cout<<"child sings well"<<endl;
    }

};
int main()
{

child obj;
obj.talktive();
obj.expert_cook();
obj.manager();
obj.singing();
return 0;
}
