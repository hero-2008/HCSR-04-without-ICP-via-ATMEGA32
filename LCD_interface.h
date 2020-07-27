/*
 * LCD_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Hero
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
void LCD_SETUP();
void LCD_INTI();
void LCD_send_CMD(u8 u8CMDcopy);
void LCD_send_CHAR(u8 u8Charcopy);
void Set_posation(u8 x, u8 y);
void LCD_print(u16 num);
#endif /* LCD_INTERFACE_H_ */
