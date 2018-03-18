#include <iostream>

using namespace std;

namespace stablestud
{
class stack_oop
{
private:
        int* stack;
        int stack_nr_elements;
public:
        stack_oop ( int size = 1 )
        {
                stack = new int [ size ];
                stack_nr_elements = 0;
                cout << "stack ... running with size: " << size << endl;
        }

        ~stack_oop ( void )
        {
                cout << "stack ... cleaning" << endl;
                delete[] stack;
        }

        void push ( int element )
        {
                stack[ stack_nr_elements++ ] = element;
        }

        int pop ( void )
        {
                if ( !stack_nr_elements )               // Prevent to access unclaimed space
                        exit ( EXIT_FAILURE );
                return stack[ --stack_nr_elements ];
        }
};

class sum_stack_oop : stack_oop
{
private:
        int sum;
public:
        sum_stack_oop ( void ) : stack_oop()        // Constructor 0 ( " : stack_oop (  ) " is optional, it will run without it )
        {
                cout << "sum stack ... running" << endl;
                this -> sum = 0;
        }

        sum_stack_oop ( int size ) : stack_oop ( size ) // Constructor 1
        {
                cout << "sum stack ... running with size " << size << endl;
                this -> sum = 0;
        }

        sum_stack_oop ( sum_stack_oop* obj, int size = 1 ) : stack_oop ( size )         // Constructor 2 ( copies other objects sum variable into this one )
        {
                cout << "sum stack ... running with size " << size << endl;
                cout << "Obj sum is " << obj -> sum << endl;
                this -> sum = obj -> sum;
        }

        ~sum_stack_oop ( void )
        {
                cout << "sum stack ... dying with sum: " << this -> sum << endl;
        }

        void push ( int element )
        {
                this -> sum += element;
                stack_oop :: push ( element );
        }

        int pop ( void )
        {
                int element = stack_oop :: pop ( );
                this -> sum -= element;
                return element;
        }

        int getSum ( void )
        {
                return sum;
        }
};
};

int main ( void )
{
        stablestud::stack_oop todo ( 3 );
        stablestud::sum_stack_oop todoz ( 3 );
        todo.push ( 83 );
        todoz.push ( 99 );
        todo.push ( 21 );
        todoz.push ( 99 );
        todo.push ( 673 );
        todoz.push ( 99 );
        cout << "Sum: " << todoz.getSum() << endl;
        stablestud::sum_stack_oop topa9 ( &todoz );
        topa9.push ( 12 );
        cout << "--todoz-- " << todoz.getSum() << endl;
        while ( todoz.getSum() )
                cout << todoz.pop() << endl;
        cout << "--todo--" << endl;
        cout << todo.pop() << endl;
        cout << todo.pop() << endl;
        cout << todo.pop() << endl;
        cout << "--topa9-- " << topa9.getSum() << endl;
        cout << topa9.pop() << endl;
//        cout << topa9.pop ( ) << endl;        // These will cause to access unclaimed space, and therefore the safety mechanism will trigger
//        cout << topa9.pop ( ) << endl;
        return 0;
}
// kate: indent-mode cstyle; indent-width 8; replace-tabs on;
