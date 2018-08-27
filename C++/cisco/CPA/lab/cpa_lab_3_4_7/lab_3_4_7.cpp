/*
 *** Lab 3.4.1 Old problems, new methods: functions ***
 *
 ** Objectives **
 *
 * Familiarize the student with:
 * - the concept of defining and invoking a function;
 * - passing argument values into a function;
 * - refactoring existing code to meet new requirements.
 *
 ** Scenario **
 *
 * Some time ago we asked you to write a program to find out if a certain year was leap or common. We want to return to the issue, but in
 * a completely different form.
 *
 * We want you to write a function equipped with the following features:
 * - its name should be "isLeap";
 * - it accepts one argument of type int representing the year number;
 * - it returns a bool value: true if the year is leap and false otherwise;
 * - it should be mute! It mustn't write anything to the output – the only way it reveals its actions is by the value it returns.
 *
 * We've prepared a skeleton of the program – fill the function body with the appropriate content.
 *
 * We've also attached the output that is expected from your program.
 *
 */


#include <iostream>

bool isLeap ( int );

int main ( void )
{
        for ( int yr { 1995 }; yr < 2018; yr++ )
                std::cout << yr << " -> " << isLeap ( yr ) << std::endl;
        return 0;
}

bool isLeap ( int year_number )
{
        return ! ( year_number % 4 );
}
