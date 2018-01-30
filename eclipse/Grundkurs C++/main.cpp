/*
 * main.cpp
 *
 *  Created on: 31 Dec 2017
 *      Author: stablestud
 */
#include <iostream>

using namespace std;

int main ( void )
{
        int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
        int n = sizeof ( vector ) / sizeof ( vector[0] );

        int *pointer[n];
        int aux;

        for(int i { 0 }; i < n; i++) {
                pointer[i] = &vector[i];
        }

        return 0;
}


