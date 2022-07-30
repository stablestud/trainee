#include <iostream>
#include <string>
using namespace std;

class Super {
//friend void Super(Super&);
private:
        int a1 = 0;
        int* ptr = new int;
protected:
        int a2 = 0;
public:
        int a3;
        Super(Super& a)
        {
                a.ptr = nullptr;
                cout << "Super(Super& a)" << endl;       
        }
        Super()
        {
                cout << "Super()" << endl;
        }
        ~Super()
        {
                cout << "~Super()" << endl;
        }
        void operator[] (Super& a)
        {
                a.ptr = nullptr;
        }
};

class Sub : public Super {
private:
        int b1 = 0;
protected:
        int b2 = 0;
public:
        int b3 = 0;
        Sub()
        {
                a2 = 9;
                a3 = 9;
                cout << "Sub()" << std::endl;
        }
        ~Sub()
        {
                cout << "~Sub()" << std::endl;
        }
};

class Suborient : public Sub {
private:
        int c1 = 0;
protected:
        int c2 = 0;
public:
        int c3 = 0;
        Suborient()
        {
                //a2 = 9;
                //a3 = 9;
                b2 = 0;
                b3 = 0;
                std::cout << "Suborient()" << std::endl;
        }
        ~Suborient()
        {
                std::cout << "~Suborient()" << std::endl;
        }
};

class SubSuborient : public Suborient {
private:
        int d1 = 0;
protected:
        int d2 = 0;
public:
        int d3 = 0;
        SubSuborient()
        {
                a2 = 9;
                a3 = 9;
                b2 = 0;
                b3 = 0;
                c2 = 9;
                c3 = 9;
                std::cout << "SubSuborient()" << std::endl;
        }
        ~SubSuborient()
        {
                std::cout << "~SubSuborient()" << std::endl;
        }
};

int main()
{
        Sub t,u,*p;
        cout << "u.a3=" << u.a3 << endl;
        cout << "t_ptr=" <<&t << " u_ptr="<<&u<<endl;
        u = *p;
        cout << "u.a3=" << u.a3 << endl;
        cout << "t_ptr=" <<&t << " u_ptr="<<&u<<endl;
}
