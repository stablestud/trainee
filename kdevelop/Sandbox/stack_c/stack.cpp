
/**
 * @Author: stablestud
 * @Date: 2018/03/11
 *
 * Stack storage, using C
 */


#include <iostream>

void push ( int* stack, int* stack_nr_elements, int element = 0 )       // Adds element to the stack's top
{                                                                       // Parameters:  - the pointer to the stacks array
                                                                        //              - a pointer to variable that stores how many elements have been saved
                                                                        //              - the actual value to add to the stack, defaults to 0 if not set
        stack [ ( *stack_nr_elements )++ ] = element;
        return;
}

int pop ( int* stack, int* stack_nr_elements )
{
        return stack [ -- ( *stack_nr_elements ) ];
}

int main ( void )
{
        int stack [ 100 ] = { 0 };      // Creates stack recklessly with size of 100
        int stack_nr_elements = 0;      // Stores number of stored elements

        // Add values to stack
        push ( stack, &stack_nr_elements, 67 );
        push ( stack, &stack_nr_elements, 109 );
        push ( stack, &stack_nr_elements );
        push ( stack, &stack_nr_elements, 109123 );
        push ( stack, &stack_nr_elements, 107779 );
        push ( stack, &stack_nr_elements, 56109 );
        push ( stack, &stack_nr_elements, 48109 );

        // Reads out stack till its empty
        while ( stack_nr_elements ) {
                std::cout << pop ( stack, &stack_nr_elements ) << std::endl;
        }

        return 0;
}
// kate: indent-mode cstyle; indent-width 8; replace-tabs on;
