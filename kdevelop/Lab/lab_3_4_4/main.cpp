/*
 *** Lab 3.4.4 Third step further – counting the days ***
 *
 ** Objectives **
 *
 * Improve the student's skills in:
 * - building a set of cooperating functions.
 *
 ** Scenario **
 *
 * Now you're ready to take on the next, more ambitious challenge.
 *
 * We need a function which:
 * - is called "daysBetween";
 * - accepts two arguments of type Date – the first represents the "since" date, while the second represents the "till" date;
 * - returns an int value, being the number of days passed between both dates;
 * - returns -1 if the "till" date is earlier than the "since" date;
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

int daysBetween ( Date d1, Date d2 )
{
        int difference { -1 };
        /*
        if( d2.year - d1.year > 0 ) {
                difference = 365 - dayOfYear ( d1 ) + dayOfYear ( d2 );
                for ( int i { d1.year + 1 }; i < d2.year; i++)
                        difference += 365 + isLeap ( i );
        } else if ( d2.year - d1.year == 0 ) {
                difference = dayOfYear ( d2 ) - dayOfYear( d1 );
        }
        */

        int since_days { 0 };
        int till_days { 0 };

        for ( int i { 0 }; i < d1.year; i++ ) {
                since_days += 365 + isLeap ( i );
        }

        for ( int i { 0 }; i < d2.year; i++ ) {
                till_days += 365 + isLeap ( i );
        }

        since_days += dayOfYear ( d1 );
        till_days += dayOfYear ( d2 );

        if ( since_days <= till_days ) {
                difference = till_days - since_days;
        }
        return difference;
}

int main ( void )
{
        Date since, till;
        cout << "Enter first date (y m d): ";
        cin >> since.year >> since.month >> since.day;
        cout << "Enter second date (y m d): ";
        cin >> till.year >> till.month >> till.day;
        cout << daysBetween ( since, till ) << endl;
        return 0;
}
