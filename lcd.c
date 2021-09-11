#include "lcd.h"

void lcd_sendCommand (uint8_t cmd)
{
GPIOB->BRR = (1<<LCD_RS); /* RS = 0 for command */
lcd_putValue(cmd);
}



void lcd_init()
{
	GPIOB->BRR = (1<<LCD_EN); //same as GPIOA->ODR &= ~(1<<LCD_EN); /* LCD_EN = 0 */
	GPIOB->BRR = (1<<LCD_RW); //same as GPIOA->ODR &= ~(1<<LCD_RW); /* LCD_RW = 0 */
	delay_us(3000); /* wait 3ms */
	lcd_sendCommand(0x38); /* init. LCD 2 line,5´7 matrix */
	lcd_sendCommand(0x0E); /* display on, cursor on */
	lcd_sendCommand(0x01); /* clear LCD */
	delay_us(2000); /* wait 2ms */
	lcd_sendCommand(0x06); /* shift cursor right */
}

