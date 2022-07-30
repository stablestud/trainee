/*
 *** Lab 3.4.3 Second step further: finding day of year **
 *
 ** Objectives **
 *
 * Improve the student's skills in:
 * - building a set of cooperating functions;
 * - using structured types.
 *
 ** Scenario **
 *
 * Let's add another powerful tool to our calendar toolkit.
 *
 * Now write a function which:
 * - is named "dayOfYear"
 * - accepts one argument of type Date – it's a structure similar to the one you were using before;
 * - returns an int value, being the number of the day within a certain year (assuming that 1st January is the first day of every year);
 * - should be mute.
 *
 */

#include <iostream>

using namespace std;

struct Date {
        int year;
        int month;
        int day;
};

bool isLeap ( int year )
{
        return ! ( year % 4 );
}

int monthLength ( int year, int month )
{
        int days { 0 };

        switch ( month ) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
                days = 31;
                break;
        case 2:
                days = ( isLeap ( year ) == 0 ) ? 28 : 29;
                break;
        case 4:
        case 6:
        case 9:
        case 11:
                days = 30;
                break;
        }
        return days;
}

int dayOfYear ( Date date )
{
        int days { 0 };
        for ( uint8_t i { 0 }; i < date.month - 1; i++ ) {      // Add for every month the total amount of days in the month to the variabel 'days', except for the last month
                days += monthLength ( date.year, i + 1 );       // The months starting at 1 and not at 0
        }
        days += date.day;               // Add leftover days
        return days;
}

int main ( void )
{
        Date d;
        cout << "Enter year month day: ";
        cin >> d.year >> d.month >> d.day;
        cout << dayOfYear ( d ) << endl;
        return 0;
}
