/*
 *** Lab 3.2.2 Matrices and pointers – a step inside ***
 *
 ** Objectives **
 *
 * Improve the student's skills in:
 * - understanding internal matrix representation;
 * - using pointers to access a desired memory location;
 * - combining for loops in order to manipulate two-dimensional arrays.
 *
 ** Scenario **
 *
 * Forgive us for asking – did you successfully complete the previous lab? If not, please go back to it and try again. Believe us – you won't
 * be able to solve this problem if you didn't solve the previous one. Sorry, but such is the tough life of a coder.
 *
 * Take a look at the code. It does almost nothing – it simply outputs the contents of a 10×10 matrix. As the matrix is initially filled with
 * zeros (why?), the output doesn't look very attractive.
 *
 * This is why we need you here – your task is to fill the matrix with values that will turn it into a multiplication table. Easy? Too easy to be
 * true. Let's raise the bar, just like we did before. You mustn't use brackets. You mustn't use indexing. Ergo, you must use pointers.
 *
 * Okay, you can use brackets – once. And only in the declaration. Nowhere else. It is possible. Really.
 */


#include <iostream>

using namespace std;

int main ( void )
{
        int matrix[10][10] { }, *matrix_pointer[10][10];

        for ( uint8_t i { 0 }; i < 10; i++ ) {
                for ( uint8_t j { 0 }; j < 10; j++ ) {
                        matrix_pointer[i][j] = &matrix[i][j];
                }
        }

        for ( uint8_t i = 0; i < 10; i++ ) {
                for ( uint8_t j = 0; j < 10; j++ ) {
                        *matrix_pointer[i][j] = ( i + 1 ) * ( j + 1 );
                        cout.width ( 4 );
                        cout << matrix[i][j];
                }
                cout << endl;
        }
        return 0;
}
