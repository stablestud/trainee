/*
 * converter.cpp
 *
 *  Created on: 8 Jan 2018
 *      Author: stablestud
 */
#include <iostream>

using namespace std;

int main(void) {
        int choice;

        do {
                choice = {0};
                cout << "\nUmrechnen von Strecken\n";
                cout << "-1- inch (Zoll)\n";
                cout << "-2- foot\n";
                cout << "-3- yard\n";
                cout << "-4- mile\n";
                cout << "-5- TERMINATE\n";
                cout << "Your choice: ";
                cin >> choice;

                if(cin.fail()) {
                        cerr << "\nError at input.\n";
                        break;
                }

                if((choice < 1) || (choice > 5)){
                        clog << "\nChoice out of range.\n";
                        cout << "Please try again!\n";
                        continue;
                }

                if(choice == 5) {
                        cout << "TERMINATING...\n";
                        break;
                }

                double m {0.0};

                cout << "Distance in meter: ";
                cin >> m;

                if(cin.fail()) {
                        cerr << "\nError at input.\n";
                        break;
                }

                cout << "Your choice is: " << m << " meter eguals ";

                switch(choice) {
                        case 1:
                                cout << m/0.0254 << " inch.\n";
                                break;
                        case 2:
                                cout << m/0.3048 << " foot.\n";
                                break;
                        case 3:
                                cout << m/0.9144 << " yard(s).\n";
                                break;
                        case 4:
                                cout << m/1609.344 << " mile(s).\n";
                                break;
                        default:
                                cerr << "Something went wrong. Aborting.";
                                return 1;
                }

        } while(choice != 5);
}
