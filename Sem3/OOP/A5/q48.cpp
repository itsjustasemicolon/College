#include <iostream>
using namespace std;
class Motor
{
    int parts;
    public:
    Motor()
    {
        parts=0;
    }
    void assign_parts(int p)
    {
        if(p<10000)
        throw "Not enough parts";
        parts=p;
    }
};
class Garage:public Motor
{
    int tools;
    public:
    Garage(int p,int t)
    {
        try
        {
            assign_parts(p);
        }
        catch(const char* e)
        {
            cout<<e<<endl;
        }
        tools=0;
        if(t<10)
        throw "Not enough tools";
        tools=t;
    }
};
int main()
{
    try
    {   
        Garage g1(5000,15);
    }
    catch(const char* e)
    {
        cout<<e<<endl;
    }
    try
    {   
        Garage g2(10001,5);
    }
    catch(const char* e)
    {
        cout<<e<<endl;
    }

}