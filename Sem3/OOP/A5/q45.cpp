#include <iostream>
using namespace std;
int main() {
    int x[]={1,2,3,4,5};
    for(int i=0;i<5;i++)
    {
        try
        {
            if(x[i]<=2)
            throw -1;
            else
            throw "exception";
        }
        catch (int e) {
            cout << "Caught an integer exception: " << e << endl;
        } 
        catch (const char* ch) {
            cout << "Caught a string exception: " << ch << endl;
        }    
    }
    return 0;
}
