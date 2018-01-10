/*
 * main.cpp
 *
 *  Created on: 31 Dec 2017
 *      Author: stablestud
 */
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main(void) {
        struct {
                vector<char> surname, firstname;
                struct {

                        struct {
                                unsigned short day, month, year;
                        } date;

                        struct {
                                unsigned short hour, minute, second;
                        } time;

                } birth;
        } student[1];

        student[0].firstname = {'M'};
#define std student[0]
#define b std.birth
#define d b.date
#define t b.time
        cout << std.firstname.size() << " " << std.surname.size() << endl;
        cout << d.day << "." << d.month << "." << d.year << endl;
        cout << t.hour << ":" << t.minute << ":" << t.second << endl;
        return 0;
}


