#include <string>
#include <iostream>

using namespace std;

class Square
{
private:
        double side;
        double area;
public:
        Square(double side);
        int getSide ( void );
        int getArea ( void );
};

Square::Square(double side)
{
        if ( side > 0 ) {
                this->side = side;
                this->area = side * side;
        } else
                this -> side = this -> area = 0;
}

int Square::getSide ( void )
{
        return this->side;
}

int Square::getArea ( void )
{
        return this->area;
}

void print(Square* square)
{
        cout << "Square: side=" << square->getSide() << " area=" << square->getArea() << endl;
}

int main()
{
        Square s(4), p(2), x(-33);
        print(&s);
        print(&p);
        print(&x);
        return 0;
}
