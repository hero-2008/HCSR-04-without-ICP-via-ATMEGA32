/*
 * main.c
 *
 *  Created on: Jul 15, 2020
 *      Author: Mohamed
 */
#include"types.h"
#include"bitwise.h"
#include"timer8_interface.h"
#include"Interupt_interface.h"
#include"timer8_private.h"
#include"DIO_interface.h"
#include"LCD_config.h"
#include"LCD_interface.h"
#include"HCSR_interface.h"
#include<avr/delay.h>
#include<avr/io.h>
#include <avr/interrupt.h>
u8 volatile static flag=0;
u8 volatile  OVER_FLOW;
u32 volatile  deg;
void main (void)
{
	Setup_hc(PORT_C,DIO_PIN_0);
	Set_Pin_direction(PORT_C,DIO_PIN_6,OUTPUT);
	Set_Pin_direction(PORT_C,DIO_PIN_7,OUTPUT);
	LCD_SETUP();
	LCD_INTI();
	Enable_Timer_counter_OV();
	Select_Normal_Timer_Mode();
	Inti_interupt_0();

	TCNT0=0;
if(flag==0)
Setup_interupt_rising_edge_INT0();
else
Setup_interupt_falling_edge_INT0();
while(1)
{
	trigger_hc(PORT_C,DIO_PIN_0);

}
}
ISR(INT0_vect)
{
	flag^=1;
	if(flag==1)
	{
		Set_Pin_val(PORT_C,DIO_PIN_6,HIGH);
		Set_Pin_val(PORT_C,DIO_PIN_7,LOW);
		Select_prescaler(No_prescaling);


	}
	else
	{
			Set_Pin_val(PORT_C,DIO_PIN_6,LOW);
			Set_Pin_val(PORT_C,DIO_PIN_7,HIGH);
			Select_prescaler(NO_CLOCK_SCOURCE);
            deg=(OVER_FLOW*255)+TCNT0;
            LCD_INTI();
            Set_posation(0, 1);
            LCD_print(deg);
            OVER_FLOW=0;
		}
}
ISR(TIMER0_OVF_vect)
{
	OVER_FLOW++;
}
