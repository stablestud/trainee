#include <iostream>

using std::cout;
using std::endl;
using std::cerr;
using std::string;

class Pet {
protected:
        string name;
        string colour;
public:
        Pet ( string n )
        {
                name = n;
        }
        
        void setColour ( string c )
        {
                colour = c;
        }

        string getColour ( void )
        {
                return this->colour;
        }
};

class Cat : public Pet {
protected:
        string type;
public:
        Cat ( string n ) : Pet ( n )
        { }
        
        void sound ( void )
        {
                cout << Pet::name << ": Meow! Meow!" << endl;
        }

        void setType ( string t )
        {
                this->type = t;
        }

        string getType ( void );
};

class Dog : public Pet {
protected:
        int typo;
public:
        Dog ( string n ) : Pet ( n )
        { }

        void sound ( void )
        {
                cout << Pet::name << ": Woof! Woof!" << endl;
        }

        void setTypo ( int t )
        {
                this->typo = t;
        }

        string* getType ( void );
};


int main ( void ) 
{
        Pet* fred = new Cat("fred"); 
        fred->setColour ( "green" );

        static_cast <Cat*> ( fred )->sound();
        static_cast <Dog*> ( fred )->sound();

        static_cast <Cat*> ( fred )->setType("Persian");

        cout << static_cast <Cat*> ( fred )->getType() << endl;
        cout << static_cast <Dog*> ( fred )->getType() << endl;

        return 0;
}

string* Dog::getType ( void )
{
        return nullptr;
}

string Cat::getType ( void )
{
        return this->type;
}
