// Datum	11.10.2017
#include <avr/io.h>				// Einbinden von Einstellungen/Definitionen/usw. für den Mikrocontroller
#include <util/delay.h>			// Einbinden der Bibliothek delay.h um Wartezeiten zu erzeugen.

/*
	In den aktuellen Linux Bibliotheken befindet sich ein Fehler, der seitens von ATMEL im aktuellen Release nicht korrigiert wurde
	Verzögerungen laufen dadurch circa um den Faktor 4 zu schnell ab.
	Als Workaround ist vorerst die korrigierende Bibliothek "delay_x.h" einzubinden
/

#include "delay_x.h"			// Einbinden der Bibliothek delay_x.h um Wartezeiten zu erzeugen.
#define F_CPU 8000000UL			// CPU Frequenz auf 8 MHz setzen,
								// Beim ATMega32 sind die Fuse Bits hexadezimal wie folgt zu setzen:
								// hfuse=D9 und lfuse=C4

/*
	Definiere F_CPU, wenn F_CPU nicht bereits vorher definiert wurde
   (z. B. durch Übergabe als Parameter zum Compiler innerhalb
   des Makefiles).
   Zusätzlich Ausgabe einer Warnung, die auf die "nachträgliche" Definition hinweist.
/
#ifndef F_CPU
#warning "F_CPU war noch nicht definiert, wird nun mit 8.000.000 definiert"
#define F_CPU 8000000UL     /* Quarz mit 8 Mhz /
#endif
*/
int main (void)					// Hauptprogramm, hier startet der Mikrocontroller
{

	DDRC |= (1 << PC5) | (1 << PC4); 		// Port C0 als Ausgang festlegen (LED1)

	while (1) {
		PORTC = (1 << PC5) | (1 << PC4);
		_delay_ms(1000);
		PORTC = (0 << PC5) | (0 << PC4);
		_delay_ms(1000);
	}							// Ende der Endlosschleife (Es wird wieder zu "while(1)" gesprungen.
	return 0;					// Wird nie erreicht, aber ohne schreibt der GCC eine Warnung.
}								// Ende des Hauptprogramms
