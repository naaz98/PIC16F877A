#include <xc.h>
#include "lcd.h"
#include "adc.h"

#define LED RD0

__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & CP_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & DEBUG_OFF);

void main() {
    unsigned int val;
    TRISB = TRISC = 0;  // Port B and Port C are Output (LCD)
    TRISD = 0;          // Port D is Output (LED)
    TRISA0 = 1;         // RA0 is Input (ADC)

    lcd_init();
    adc_init();

    while (1) {
        cmd(0x80);
        val = adc();
        show("LIGHT INT : ");
        if (val > 150) {
            show("LOW ");
            LED = 1;
        } else {
            show("HIGH");
            LED = 0;
        }
    }
}
