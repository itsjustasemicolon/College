#include <iostream>
using namespace std;

class Complex
{
private:
    float real, imag;

public:
    Complex(float r, float i)
    {
        real = r;
        imag = i;
    }
    void disp()
    {
        cout << '(' << real << ',' << imag << ")";
    }
};

template <class T>
class Stack
{
private:
    T *arr;
    int top;
    int size;

public:
    Stack(int);   
    void push(T); 
    T pop();      
    void disp(); 
};

template <class T>
Stack<T>::Stack(int sz)
{
    size = sz;
    arr = (T *)malloc(size * sizeof(T));
    top = -1;
}

template <class T>
void Stack<T>::push(T x)
{
    if (top == size - 1)
    {
        cout << "Overflow\n";
        return;
    }
    arr[++top] = x;
}

template <class T>
T Stack<T>::pop()
{
    if (top == -1){
        return -99999;
    }
    else{
        return arr[top--];
    }
}

template <>
Complex Stack<Complex>::pop()
{
    if (top == -1){
        return Complex(-99999, -99999);
    }
    else{
        return arr[top--];
    }
}

template <class T>
void Stack<T>::disp()
{
    cout << "Contents of stack:\n";
    int ptr = top;
    while (ptr >= 0)
    {
        cout << arr[ptr--] << " ";
    }
    cout << "\n";
}

template <>
void Stack<Complex>::disp()
{
    cout << "Contents of stack:\n";
    int ptr = top;
    while (ptr >= 0)
    {
        arr[ptr--].disp();
        cout << " ";
    }
    cout << "\n";
}

int main()
{
    Stack<int> st1(10);
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    int d = st1.pop();
    st1.push(5);
    st1.disp();
    d = st1.pop();
    d = st1.pop();
    st1.push(6);
    st1.disp();

    Stack<Complex> st2(10);
    st2.push(Complex(1, 2));
    st2.push(Complex(2, -1));
    st2.push(Complex(3, -4));
    st2.push(Complex(1, 4));
    st2.push(Complex(-6, 1));
    Complex c = st2.pop();
    st2.disp();
    c = st2.pop();
    st2.push(Complex(9, -2));
    st2.disp();
}