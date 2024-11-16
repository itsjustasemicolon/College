#include <iostream>
using namespace std;
class Stack
{
    int size;
    int *arr;
    int top;
    public:
    Stack(int s)
    {
        size=s;
        top=0;
        arr=new int[size];
    }

    void push(int n)
    {
        if(top<=size-1)
        arr[top++]=n;
        else
        throw "Stack Overflow";
    }

    int pop()
    {
        int p;
        if(top<1)
        throw "Stack underflow";
        return arr[--top];
    }
};

int main()
{
    Stack ob(3);
    try{
        ob.push(1);
        ob.push(2);
        ob.push(3);
        ob.push(4);
    }
    catch(const char* e)
    {
        cout<<e<<endl;
    }
    try{
        cout<<ob.pop()<<endl;
        cout<<ob.pop()<<endl;
        cout<<ob.pop()<<endl;
        cout<<ob.pop()<<endl;
    }
    catch(const char* e)
    {
        cout<<e<<endl;
    }
}