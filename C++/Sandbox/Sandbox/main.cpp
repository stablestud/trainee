#include <iostream>

class BASE
{
public:
        virtual void func ( void )
        {
                std::cout << "It func" << std::endl;
        }
};

class DERIVED : public BASE
{
public:
        void func ( void )
        {
                std::cout << "It func deeper" << std::endl;
        }

        void specialo ( void )
        {
                func();
                std::cout << "|| upper is mine " << std::endl;
        }
};

void func ( BASE& );

int main ( void )
{
        BASE ok_cool;
        DERIVED gang;
        
        func ( ok_cool );
        std::cout << "..................." << std::endl;
        func ( gang );

        return 0;
}

void func ( BASE& base )
{
        try {
                dynamic_cast<DERIVED&>(base).specialo();
        
        } catch (...) {};

        try {
                dynamic_cast<BASE&>(base).func();

        } catch (...) {};
}
