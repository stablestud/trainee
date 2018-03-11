/**
 * @Author: stablestud
 * @Date: 2018/03/11
 * 
 */


#include <iostream>

using namespace std;

void push ( int element, int* stack, int* stack_nr_elements )
{
        stack [ ( *stack_nr_elements )++ ] = element;
        return;
}

int pop ( int* stack, int* stack_nr_elements )
{
        int element = stack [ --( *stack_nr_elements ) ];
        stack [ *stack_nr_elements ] = 0;
        return element;
}

int main ( int argc, char **argv )
{
        int stack [ 100 ] = { 0 };         // Creates stack recklessly with size of 100
        int stack_nr_elements = 0;      // Stores number of stored elements

        // Add values to stack
        push ( 67, stack, &stack_nr_elements );
        push ( 109, stack, &stack_nr_elements );
        push ( 309, stack, &stack_nr_elements );
        push ( 109123, stack, &stack_nr_elements );
        push ( 107779, stack, &stack_nr_elements );
        push ( 56109, stack, &stack_nr_elements );
        push ( 48109, stack, &stack_nr_elements );

        cout << "I'm at: " << stack_nr_elements << endl;

        // Reads out stack till its empty
        while ( stack_nr_elements ) {
                cout << pop ( stack, &stack_nr_elements ) << endl;
        }

        cout << "I'm at: " << stack_nr_elements << endl;
        return 0;
}
// kate: indent-mode cstyle; indent-width 8; replace-tabs on; 
