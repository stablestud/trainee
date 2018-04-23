/*
 *** Lab 3.2.1 Vectors and pointers: first try ***
 *
 ** Objectives **
 *
 * Familiarize the student with:
 * - declaring pointer variables;
 * - assigning values to pointer variables;
 * - using incrementation to move the pointer through adjacent memory locations.
 *
 ** Scenario **
 *
 * Look at the code below. It doesn't look scary, right?
 *
 * Your task doesn't look scary either – you just have to find the smallest element in the vector. But there's one condition – you mustn't use
 * indexing. In other words, using brackets in your code is strictly prohibited.
 *
 * Hint: You may use as many pointers as you wish.
 *
 * Forgive us that we don't show you any sample output. We would much rather see your code – it's much more interesting.
 *
 */

#include <iostream>
#include <limits>

using namespace std;

int main ( void )
{
        int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
        int n = sizeof ( vector ) / sizeof ( vector[0] );       // Get the array size of the vector ( total bytes of array / one array element )

        int *pointer[n];                // Declaring array pointer

        for ( uint8_t i { 0 }; i < n; i++ )     // Assign array adresses to the pointer
                pointer[i] = &vector[i];

        int max { *pointer[0] };                // Declaring max variable with the first pointer's value

        for ( uint8_t i { 0 }; i < n; i++ )     // Compare each pointer's value to the max variable, keep only the lowest
                max = ( max < *pointer[i] ) ? max : *pointer[i];

        cout << "The smallest number is: " << max << endl;

        return 0;
}
