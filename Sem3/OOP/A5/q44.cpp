#include <iostream>
using namespace std;
int main()
{
    int divisor,dividend;
    cin>>divisor;
    cin>>dividend;
    try
    {
        if(divisor==0)
        throw -1;
        else
        cout<<(dividend/divisor)<<endl;
    }
    catch(int n)
    {
        cout<<"Division by zero";
    }
    
}