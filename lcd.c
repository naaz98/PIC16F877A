#include <xc.h>
#include "lcd.h"

#define delay for(i=0;i<=1000;i++)
#define rs RC0
#define rw RC1
#define e RC2

int i;

void lcd_init(void) {
    cmd(0x38);
    cmd(0x0c);
    cmd(0x06);
    cmd(0x80);
}

void cmd(unsigned char a) {
    PORTB = a;
    rs = 0;
    rw = 0;
    e = 1;
    delay;
    e = 0;
}

void dat(unsigned char b) {
    PORTB = b;
    rs = 1;
    rw = 0;
    e = 1;
    delay;
    e = 0;
}

void show(const char *s) {
    while (*s) {
        dat(*s++);
    }
}
