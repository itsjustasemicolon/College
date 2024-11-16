#include <iostream>
using namespace std;
class Lane
{
    int direction;
    public:
    Lane(int d)
    {
        direction=d;
    }
    int get_d()
    {
        return direction;
    }
};
int main()
{
    Lane vehicle1(1);
    Lane vehicle2(-1);
    try
    {
        if(vehicle1.get_d()!=vehicle2.get_d())
        throw "Collision possible";
    }
    catch(const char* e)
    {
        cout<<e<<endl;
    }
}