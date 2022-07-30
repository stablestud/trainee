/*
 *** Lab 3.8.1 Overloading functions ***
 *
 ** Objectives **
 *
 * Improve the student's skills in:
 * - using "passing by reference" mechanisms;
 * - and familiarize the student with the concepts of overloading function.
 *
 ** Scenario **
 *
 * Sorry for bothering you, but we have to tell you that the function you implemented last time needs to be supplemented with another one
 * that performs (more or less) the same actions, but uses different type of data. We can't say anything more, but we're sure that you'll be
 * able to deduce all our intentions and needs from the code below.
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

void increment ( int *num, int by = 1 )
{
        *num += by;
}

void increment ( float *num, float by = 1.0f )
{
        *num += by;
}

int main ( void )
{
        int intvar = 0;
        int * ptr = &intvar;

        float floatvar = 1.5;
        float *fptr = &floatvar;

        for ( int i = 0; i < 10; i++ )
                if ( i % 2 ) {
                        increment ( ptr );
                        increment ( fptr , sqrt ( intvar ) );
                } else {
                        increment ( ptr , i );
                        increment ( fptr );
                }

        cout << intvar * floatvar << endl;

        return 0;
}
