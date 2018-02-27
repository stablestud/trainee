/* Alexander Gottweis, OBFd73, 27.02.2018 */

#include <iostream>

using namespace std;

int main ( void )
{
        uint length = 0, input;

        cout << "Ziffer-Sortierer von klein zu GROSSE Ziffern" << endl;
        cout << "Bitte geben Sie eine zu sortierende, ganze Zahl ein: ";
        cin >> input;                                           /* Lese Zahl vom Benutzer ein */

        for ( uint aux = input; aux != 0; length++ ) {          /* Ermitteln der Zahllänge. */
                aux /= 10;
        }

        uint tree[length];      // Array das die einzelnen, abgespalteten Ziffern speichert
        uint *ptrtree[length];  /* Erstellung eines Pointer das auf den Array 'tree' verweist.
                                 * Benutze ich um nicht die Werte im Speicher zu verschieben,
                                 * sondern nur die Pointers die darauf zeigen.
                                 * Dies soll angeblich die Geschwindigkeit erhöhen.
                                 * ?? Obwohl pointer 8 byte haben und int bei mir 4 byte und
                                 * es somit eigentlich länger dauern müsste. ??
                                 */

        for ( uint i = length - 1, aux = input; aux != 0; i-- ) { // Definition eines Arrays, dass die einzelnen Ziffern zwischen speichert.
                tree[i] = aux % 10;                             // Ermittle letzte Zahl anhand des Modulus.
                ptrtree[i] = tree + i;                          // Verweis des Pointers auf Ziffer der Position tree[i].
                aux /= 10;                                      // Zahl um eine Stelle kürzen.
        }

        cout << "Ihre Eingegebene Zahl: ";

        for ( uint i = 0; i < length; i++ ) {                   /* Ausgabe des Arrays. */
                cout << tree[i];
        }


        cout << endl;

        bool swapped;                                           /* Variable die festsetzt ob etwas Verschoben wurde oder nicht. */

        do {                                                    /* Schleife die solange läuft bis keine Verschiebung/Sortierung mehr statt fand. */
                swapped = false;

                for ( uint i = 0, *aux; i < length - 1; i++ ) { /**/

                        if ( *ptrtree[i] > *ptrtree[i+1] ) {    // Wenn Wert/Ziffer des Pointers größer als Wert/Ziffer des nächsten Pointers, dann ...
                                aux = ptrtree[i];               // Weise Ziffer auf Auslagerungs Variable.
                                ptrtree[i] = ptrtree[i+1];      // Weise Ziffer der nächsten Array Position auf die jetzige Position.
                                ptrtree[i+1] = aux;             // Weise Auslagerungs Ziffer auf die nächste Array Position.
                                swapped = true;                 // Wir haben die Reihenfolge geändert, deswegen muss die Variable auf 'true' gesetzt werden.
                        }
                }

        } while ( swapped );                                    // Führe schleife aus solange nix mehr an der Reihenfolge geändert wurde.

        cout << "Sortierte Zahl:        ";
        for ( uint i = 0; i < length; i++ ) {                   /* Ausgabe des Arrays */
                cout << *ptrtree[i];
        }
        cout << endl;

        return 0;
}
// kate: indent-mode cstyle; indent-width 8; replace-tabs on;
