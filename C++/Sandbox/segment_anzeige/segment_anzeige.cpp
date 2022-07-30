/*
 * segment_anzeige.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: Vladislav
 */

#include <avr/io.h>
#include <util/delay.h>
#include "segment.h"

int main(void) {

        setOutput();
        while (1) {
              for(int i = 0;i < 16;i++) {
                        printNumber(1);
                        _delay_ms(1000);
                        clearSegment();
              }

        }
}
