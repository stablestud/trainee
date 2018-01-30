/*
 * segment.h
 *
 *  Created on: Jan 20, 2018
 *      Author: Vladislav
 */

/*
 * 7,5 Segment anzeige
 *
 *
 *    _7_         _a_         10 9 8 7 6    g f GRN a b
 *   |   |       |   |             x             x
 *  9|_10|6     f|_g_|b
 *   |   |       |   |             x   .         x    .
 *  1|_2_|4 .5  e|_d_|c .DP    1 2 3 4 5    e d GRN c DP
 *
 *
 *   1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10
 *   e  |  d  | GRN |  c  | .DP |  b  |  a  | GRN |  f  |   g
 *  D8  |  D9 |     |  D2 |  D7 |  D3 |  D4 |     |  D5 |  D6
 *  PB0 | PB1 |     | PD2 | PD7 | PD3 | PD4 |     | PD5 | PD6
 *
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_

// PORTD - PD4 - Auf Pin: D4
#define _aOn _SFR_IO8(0x0B) |= 0b10000
#define _aOff _SFR_IO8(0x0B) &= ~0b10000

// PORTD - PD3 - Auf Pin: D3
#define _bOn _SFR_IO8(0x0B) |= 0b1000
#define _bOff _SFR_IO8(0x0B) &= ~0b1000

// PORTD - PD2 - Auf Pin: D2
#define _cOn _SFR_IO8(0x0B) |= 0b100
#define _cOff _SFR_IO8(0x0B) &= ~0b100

// PORTB - PB1 - Auf Pin: D9
#define _dOn _SFR_IO8(0x05) |= 0b10
#define _dOff _SFR_IO8(0x05) &= ~0b10

// PORTB - PB0 - Auf Pin: D8
#define _eOn _SFR_IO8(0x05) |= 0b1
#define _eOff _SFR_IO8(0x05) &= ~0b1

// PORTD - PD5 - Auf Pin: D5
#define _fOn _SFR_IO8(0x0B) |= 0b100000
#define _fOff _SFR_IO8(0x0B) &= ~0b100000

// PORTD - PD6 - Auf Pin: D6
#define _gOn _SFR_IO8(0x0B) |= 0b1000000
#define _gOff _SFR_IO8(0x0B) &= ~0b1000000

// PORTD - PD7 - Auf Pin: D7
#define _DPOn _SFR_IO8(0x0B) |= 0b10000000
#define _DPOff _SFR_IO8(0x0B) &= ~0b10000000

void clearSegment() {
        /*
         * Schaltet alle LEDs der Segmentanzeige aus.
         */
        _SFR_IO8(0x05) &= ~0b11; // PORTB
        _SFR_IO8(0x0B) &= ~0b11111100; // PORTD
}

void setOutput() {
        /*
         * Setzt das Datenregister (DDRD und DDRB) auf Ausgang.
         */
        _SFR_IO8(0x04) |= 0b11; // PORTB
        _SFR_IO8(0x0A) |= 0b11111100; // PORTD
}

void printNumber(int number) {
        switch (number) {
                case 0:
                        _aOn;
                        _bOn;
                        _cOn;
                        _dOn;
                        _eOn;
                        _fOn;
                        break;
                case 1:
                        _bOn;
                        _cOn;
                        break;
                case 2:
                        _aOn;
                        _bOn;
                        _gOn;
                        _eOn;
                        _dOn;
                        break;
                case 3:
                        _aOn;
                        _bOn;
                        _gOn;
                        _cOn;
                        _dOn;
                        break;
                case 4:
                        _fOn;
                        _gOn;
                        _bOn;
                        _cOn;
                        break;
                case 5:
                        _aOn;
                        _fOn;
                        _gOn;
                        _cOn;
                        _dOn;
                        break;
                case 6:
                        _aOn;
                        _fOn;
                        _eOn;
                        _dOn;
                        _cOn;
                        _gOn;
                        break;
                case 7:
                        _aOn;
                        _bOn;
                        _cOn;
                        break;
                case 8:
                        _aOn;
                        _bOn;
                        _cOn;
                        _dOn;
                        _eOn;
                        _fOn;
                        _gOn;
                        break;
                case 9:
                        _aOn;
                        _bOn;
                        _cOn;
                        _dOn;
                        _fOn;
                        _gOn;
                        break;
                case 10: /* A */
                        _aOn;
                        _bOn;
                        _cOn;
                        _gOn;
                        _fOn;
                        _eOn;
                        break;
                case 11: /* b */
                        _fOn;
                        _eOn;
                        _dOn;
                        _cOn;
                        _gOn;
                        break;
                case 12: /* c */
                        _aOn;
                        _fOn;
                        _eOn;
                        _dOn;
                        break;
                case 13: /* d */
                        _bOn;
                        _cOn;
                        _dOn;
                        _eOn;
                        _gOn;
                        break;
                case 14: /* E */
                        _aOn;
                        _fOn;
                        _gOn;
                        _eOn;
                        _dOn;
                        break;
                case 15: /* F */
                        _aOn;
                        _fOn;
                        _gOn;
                        _eOn;
                        break;
        }
}
#endif /* SEGMENT_H_ */
