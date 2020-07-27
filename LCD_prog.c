/*
 * LCD_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Hero
 */
#include"types.h"
#include"bitwise.h"
#include"DIO_interface.h"
#include"LCD_interface.h"
#include"LCD_config.h"
#include<avr/delay.h>
#include<stdlib.h>
void LCD_SETUP()
{
	SET_PORT_DIR(Data_port ,OUTPUT);
	Set_Pin_direction(CMD_port,RS_PIN,OUTPUT);
	Set_Pin_direction(CMD_port,RW_PIN,OUTPUT);
	Set_Pin_direction(CMD_port,EN_PIN,OUTPUT);
}
void LCD_INTI()
{
	_delay_ms(30);
	LCD_send_CMD(LCD_HOME);
	_delay_ms(15);
	LCD_send_CMD(LCD_FUNCSET_8BIT);
	_delay_ms(1);
	LCD_send_CMD(LCD_DISPON_CURSON);
	_delay_ms(1);
	LCD_send_CMD(LCD_CLR);
	_delay_ms(15);
	LCD_send_CMD(LCD_ENTRYMODE);
	_delay_ms(2);
}
void LCD_send_CMD(u8 u8CMDcopy)
{
	Set_Pin_val(CMD_port,RS_PIN,LOW);
	Set_Pin_val(CMD_port,RW_PIN,LOW);
	Set_Pin_val(CMD_port,EN_PIN,HIGH);
	GIVE_PORT_VAL(Data_port ,u8CMDcopy);
	Set_Pin_val(CMD_port,EN_PIN,LOW);
	_delay_ms(5);
	Set_Pin_val(CMD_port,EN_PIN,HIGH);
	_delay_ms(10);
}
void LCD_send_CHAR(u8 u8Charcopy)
{
	Set_Pin_val(CMD_port,RS_PIN,HIGH);
	Set_Pin_val(CMD_port,RW_PIN,LOW);
	Set_Pin_val(CMD_port,EN_PIN,HIGH);
	GIVE_PORT_VAL(Data_port ,u8Charcopy);
	Set_Pin_val(CMD_port,EN_PIN,LOW);
	_delay_ms(5);
	Set_Pin_val(CMD_port,EN_PIN,HIGH);
	_delay_ms(10);
}
void Set_posation(u8 x, u8 y)
{
	switch (x) {
		case 1:
			LCD_send_CMD((0xb80) + y);
			break;
		case 2:
			LCD_send_CMD((0xbc0) + y);
			break;
}
}
void LCD_print(u16 num) {
		u16 size,index,temp,result,end,c,count=0;
		u8 x[8];

		for(index=0;index<8;index++)
		{
			temp=num;
			result=temp%10;
			x[index]=result+'0';
			num/=10;
		}
		size=sizeof(x)/sizeof(x[0]);
		end=size-1;
		for(c=0;c<size/2;c++)
		{
			temp=x[c];
			x[c]=x[end];
			x[end]=temp;
			end--;
		}
			index=0;
			while(x[index]=='0')
			{
				count++;
			index++;
			}
			for(index=(count);index<size;index++)
				{
				LCD_send_CHAR(x[index]);
				}
}
