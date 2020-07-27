/*
 * HCSR_prog.c
 *
 *  Created on: Jul 15, 2020
 *      Author: Mohamed
 */
#include"types.h"
#include"bitwise.h"
#include"DIO_interface.h"
#include"HCSR_interface.h"
#include<avr/delay.h>
void Setup_hc(u8 u8port,u8 hc_trigger_pin)
    {
	Set_Pin_direction(u8port,hc_trigger_pin ,OUTPUT);
    }

void trigger_hc(u8 u8port,u8 hc_trigger_pin)
    {
	Set_Pin_val(u8port,hc_trigger_pin,HIGH);
	_delay_ms(10);
	Set_Pin_val(u8port,hc_trigger_pin,LOW);
	_delay_ms(10);
    }




