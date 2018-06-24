#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class A {
public:
        virtual void foo()
        {
                cout << "A::foo()" << endl;
        }
};
    
class B : public A {
public:
        void foo()
        {
                cout << "B::foo()" << endl;
        }
        void bar()
        {
                cout << "B::bar()" << endl;
        }
};

class C : public A {
public:
        void foo()
        {
                cout << "C::foo()" << endl;
        }
};
     
int main() {
        A* y = new B;
        C* x = new C;
        A* z = new A;

        try {
                static_cast<C*>(y)->foo();
                static_cast<B*>(dynamic_cast<A*>(x))->foo();
                dynamic_cast<B*>(z)->bar();
        } catch (...) {
                cerr << "Caught!" << endl;
        }
}
