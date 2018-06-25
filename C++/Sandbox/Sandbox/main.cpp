#include <iostream>
#include <string>
using namespace std;

class A {
        int a;
protected:
        float b;
public:
        char c;
};

class B : protected A {
public:
        B()
        {
                c = 9;
                b = 7;
        }
        void print () {
                std::cout << c << b << endl;
        }
};

int main(void) {
        B b;
        b.print();
        return 0;
}
