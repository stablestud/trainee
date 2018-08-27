#include <iostream>

using namespace std;

class House
{
public:
        House ( int side )
        {
                this -> side = side;
                this -> changed = true;
        }

        int getSide ( void )
        {
                return this -> side;
        }

        int getArea ( void )
        {
                if ( this -> changed )
                        this -> updateArea();
                return this -> area;
        }
        void setSide ( int );
private:
        int area;
        int side;
        bool changed;
        void updateArea ( void );
};

void House::updateArea ( void )
{
        this -> area = this -> side * this -> side;
        std::cout << "Updating Area..." << std::endl;
        this -> changed = false;
}

void House::setSide ( int side )
{
        this -> side = side;
        this -> changed = true;
}

int main ( void )
{
        House newone = 20;
        std::cout << newone.getSide() << std::endl;
        std::cout << newone.getArea() << std::endl;
        std::cout << newone.getArea() << std::endl;
        newone.setSide(800);
        std::cout << newone.getArea() << std::endl;
        return 0;
}
