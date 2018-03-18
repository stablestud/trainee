#include <iostream>

using namespace std;

struct mel {
        int valve;
        char str[3];

         void func ( void )
         {
                 this -> valve = *(this -> str);
         }
};

namespace stablestud {
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
                sum_stack_oop ( void ) : stack_oop ( )        // Constructor 0
                {
                        this -> sum = 0;
                }

                sum_stack_oop ( int size ) : stack_oop ( size ) // Constructor 1
                {
                        this -> sum = 0;
                }

                sum_stack_oop ( sum_stack_oop& obj, int size = 1 ) : stack_oop ( size )         // Constructor 2
                {
                        this -> sum = obj.sum;
                }

                sum_stack_oop ( struct mel itachi ) : stack_oop ( itachi.valve )                // Constructor 3
                {
                        itachi.func ( );
                        this -> sum = itachi.valve;
                        for ( int i = 0; i < sizeof itachi.str; i++ )
                                cout << itachi.str[i];
                        cout << endl;
                }

                void push ( int element )
                {
                        sum += element;
                        stack_oop :: push ( element );
                }

                int pop ( void )
                {
                        int element = stack_oop :: pop ( );
                        sum -= element;
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
        cout << "Sum: " << todoz.getSum ( ) << endl;
        stablestud::sum_stack_oop topa9 ( todoz );
        struct mel STRU { 999, "Me" };
        stablestud::sum_stack_oop toink ( STRU );
        topa9.push ( 12 );
        toink.push ( 77 );
        cout << "--toink-- " << toink.getSum ( ) << endl;
        cout << toink.pop ( ) << endl;
        cout << "--todoz-- " << todoz.getSum ( ) << endl;
        cout << todoz.pop ( ) << endl;
        cout << todoz.pop ( ) << endl;
        cout << todoz.pop ( ) << endl;
        cout << "--todo--" << endl;
        cout << todo.pop ( ) << endl;
        cout << todo.pop ( ) << endl;
        cout << todo.pop ( ) << endl;
        cout << "--topa9-- " << topa9.getSum ( ) << endl;
        cout << topa9.pop ( ) << endl;
//        cout << topa9.pop ( ) << endl;        // These will cause to access unclaimed space, and therefore the safety mechanism will trigger
//        cout << topa9.pop ( ) << endl;
        return 0;
}
