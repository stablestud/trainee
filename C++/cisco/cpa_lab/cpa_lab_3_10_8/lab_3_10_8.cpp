/*
 *** Lab 3.10.1 Using pseudorandom values - a little lottery ***
 *
 ** Objectives **
 *
 * Improve the student's skills in:
 * - using standard library functions;
 * - using vectors;
 * - and familiarize the student with the concept of pseudorandom number generation and use.
 *
 ** Scenario **
 *
 * Don't think we want to encourage you to start gambling – nothing could be more wrong. We only want you to write a code that tries to
 * "predict" (note the quotes) the numbers for the lottery.
 *
 * There are many different lotteries so your program should be flexible. It will have to know two basic parameters: how many balls are in
 * the machine and how many of them are drawn. Therefore, your code must input two int values reflecting these restrictions.
 *
 * Next, the program should "draw" (note the quotes again) the required number of balls. To simulate the process of drawing, we'll use the
 * so-called "pseudo-random number generator" – an algorithm producing a series of numbers which behave as if they were "drawn",
 * although the values are strictly deterministic and (sad but true) completely predictable.
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

inline int correct_percentage ( int correct, int ballsno )
{
        return ballsno / 100 * correct;
}

int main ( void )
{
                int maxball = 0;
                int ballsno = 0;

                std::cout << "Max ball number? ";
                std::cin >> maxball;

                if ( maxball > 50 )
                        std::cout << "-- Good luck guessing that!" << std::endl;

                std::cout << "How many balls? ";
                std::cin >> ballsno;

                if ( ballsno > 10 )
                        std::cout << "-- Feeling lucky today, don't we?" << std::endl;

                int *user_guess = new int [ballsno];
                int *actual_value = new int [maxball];

                int correct = 0, row = 0, max_row = 0;

                for ( int i = 0; i < ballsno; i++ ) {   // Generate random numbers and store them into the actual_value array

                        srand ( time ( NULL ) );

                        actual_value[i] =  rand() % maxball + 1;
                        
                        std::cout << "[" << i + 1 << "]: ";
                        std::cin >> user_guess[i];

                        if ( user_guess[i] == actual_value[i] ) {
                                correct++;
                                row++;
                        } else {
                                max_row = ( max_row > row ) ? max_row : row;
                                row = 0;
                        }
                }
                std::cout << "\nFollowing numbers have been pulled:\nACTUAL: ";
                
                for ( int i = 0; i < ballsno; i++ )
                        std::cout << std::cout.width(4) << actual_value[i];
                
                std::cout << "\nYOUR:   ";
                
                for ( int i = 0; i < ballsno; i++ )
                        std::cout << std::cout.width(4) << user_guess[i];
                
                std::cout << "\nYou got " << correct << " correct and the longest streak was: " << max_row << ".\n";
                
                if ( correct_percentage ( correct, ballsno ) < 20 ) {
                        std::cout << "If I would be you, I would never touch lottery again ...\n";
                }

                delete[] actual_value;
                delete[] user_guess;
                system("sleep 15");
        return 0;
}
