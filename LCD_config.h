/*
 * LCD_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Hero
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
#define  LCD_CLR               0x01      /* replace all characters with ASCII 'space' */
#define  LCD_HOME              0x02      /* return cursor to first position on first line */
#define  LCD_ENTRYMODE         0x06      // shift cursor from left to right on read/write
#define LCD_DISPOFF            0x08      // turn display off
#define LCD_DISPON_CURSON      0x0E      // display on, cursor off, don't blink character
#define LCD_FUNCRESET          0x30      // reset the LCD
#define LCD_FUNCSET_8BIT       0x38      // 8-bit data, 2-line display, 5 x 7 font
#define LCD_SETCURSOR          0x80      // set cursor position
#define LCD_DISPON_CURSBLINK   0x0F      //display on , cursor blinking
#define LCD_DISPON_CURSOFF     0x0C      //display on ,cursor off


#define    RS_PIN             DIO_PIN_0
#define    RW_PIN             DIO_PIN_1
#define    EN_PIN             DIO_PIN_2
#define    Data_port          PORT_A
#define    CMD_port           PORT_B


#endif /* LCD_CONFIG_H_ */
