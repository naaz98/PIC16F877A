#include <xc.h>
#include "adc.h"

void adc_init(void) {
    ADCON1 = 0xC0;  // Configure ADC settings
    ADCON0 = 0x81;  // Turn on ADC and select channel 0 (RA0)
}

unsigned int adc(void) {
    ADCON0bits.GO_nDONE = 1;        // Start conversion
    while(ADCON0bits.GO_nDONE);     // Wait for conversion to finish
    return ((ADRESH << 8) + ADRESL) / 3 - 1; // Return the result
}