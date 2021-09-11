#include "stm32f10x.h"
#include "Delay.h"
#define LCD_RS 7
#define LCD_RW 6
#define LCD_EN 5

void lcd_init(void);
void lcd_sendCommand (uint8_t);


