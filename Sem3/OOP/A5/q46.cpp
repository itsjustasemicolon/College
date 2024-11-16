#include <iostream>
using namespace std;
class Test {
    public:
    class Custom 
    {
        const char* description;
        public:
        Custom(const char* desc)
        {
            description=desc;
        }
        void disp()
        {
            cout<<description<<endl;
        }
    };
    void test()
    {
        throw Custom("Testing the Custom Exception class");
    }
};

int main() {
    Test obj;

    try {
        
        obj.test();
    } 
    catch (Test::Custom ob) {
        ob.disp();
    }

    return 0;
}
