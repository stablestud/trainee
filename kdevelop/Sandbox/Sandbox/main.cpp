#include <iostream>

using namespace std;

class ClassSupreme
{
protected:
        static int level;
public:
        ClassSupreme ( void )
        {
                cout << "Initializing ClassSupreme..." << endl;
        }

        ~ClassSupreme ( void )
        {
                cout << "Killing ClassSupreme..." << endl;
        }

};

class SubClassSupreme : ClassSupreme
 {
 public:
        SubClassSupreme ( void )
        {
                cout << "Initializing SubClassSupreme... total level: " << ClassSupreme::level++ << endl;
        }

        ~SubClassSupreme ( void )
        {
                cout << "Killing SubClassSupreme..." << endl;
        }
};

class SubSubClassSupreme : SubClassSupreme
{
public:
        SubSubClassSupreme ( void )
        {
                cout << "Initializing SubSubClassSupreme... total level: " << endl;
        }

        ~SubSubClassSupreme ( void )
        {
                cout << "Killing SubSubClassSupreme..." << endl;
        }
};

int ClassSupreme::level = 0;

int main ( void )
{
        ClassSupreme A;
        SubClassSupreme b;
        SubSubClassSupreme a;

        return 0;
}
