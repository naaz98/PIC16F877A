
#ifndef LCD_H
#define LCD_H

void lcd_init(void);
void cmd(unsigned char a);
void dat(unsigned char b);
void show(const char *s);

#endif