/*
 * timer8_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Hero
 */
#include"types.h"
#include"bitwise.h"
#include"timer8_private.h"
#include"timer8_interface.h"
#include"Interupt_interface.h"
#include"Interupt_pravite.h"
#include"DIO_interface.h"
//////////////////////////////////////setups///////////////////////////////
void Enable_Timer_counter_OV()
{
	SET_BIT(SREG,I);
	SET_BIT(TIMSK,TOIE0);
}
void Enable_Counter_Output_Match()
{
	SET_BIT(SREG,I);
	SET_BIT(TIMSK,OCIE0);
}
//////////////////////////////////////////////////////////////////////////////
///////////////////////Timer_PMW_MODS_SELECT//////////////////////////////////
void Select_Normal_Timer_Mode()
{
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
}
void Select_PWM_Phase_Correct_Mode()
{
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
}
void Select_Clear_Timer_Compare_Mode()
{
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
}
void Select_Fast_PWM_Mode()
{
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
}
//////////////////////////////////////////////////////////////////
/////////////////////SELECT WAVE FORM ON OC0 PIN//////////////////
void OC0_Normal()
{
	CLR_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
}
void OC0_Toggle()
{
	SET_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
}
void OC0_Clear()
{
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}
void OC0_Set()
{
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}
/////////////////////////////////////////////////////////////////////////
/////////////////PRESCALER////////////////////////////////////////////
void Select_prescaler(u8 Statuse)
{
	if((Statuse>=NO_CLOCK_SCOURCE)&&(Statuse<=CLK_1024))
	{
		switch(Statuse)
		{
		case NO_CLOCK_SCOURCE:
		     {
		    	 CLR_BIT(TCCR0,CS00);
		    	 CLR_BIT(TCCR0,CS01);
		    	 CLR_BIT(TCCR0,CS02);
		     }
		     break;
		case No_prescaling:
		     {
		    	 SET_BIT(TCCR0,CS00);
				 CLR_BIT(TCCR0,CS01);
				 CLR_BIT(TCCR0,CS02);
		     }
			 break;
		case CLK_8:
			 {
				 CLR_BIT(TCCR0,CS00);
				 SET_BIT(TCCR0,CS01);
				 CLR_BIT(TCCR0,CS02);
			 }
		     break;
		case CLK_64:
			 {
				 SET_BIT(TCCR0,CS00);
				 SET_BIT(TCCR0,CS01);
				 CLR_BIT(TCCR0,CS02);
			 }
			break;
		case CLK_256:
			 {
				  CLR_BIT(TCCR0,CS00);
				  CLR_BIT(TCCR0,CS01);
				  SET_BIT(TCCR0,CS02);
			 }
		    break;
		case CLK_1024:
			{
				  SET_BIT(TCCR0,CS00);
				  CLR_BIT(TCCR0,CS01);
				  SET_BIT(TCCR0,CS02);
			}
		   break;
		}
	}
	else
	{
		//do no thing
	}
}
///////////////////////////////////////////////////////////////////////////////////////
void Select_CLK_Source(u8 EX_CLK)
{
	Set_Pin_direction(PORT_B,DIO_PIN_0,OUTPUT);
	if((EX_CLK>=EX_Fall_edge)&&(EX_CLK<=EX_Rise_edge))
	{
		switch(EX_CLK)
		{
		case EX_Fall_edge:
		    {
		    	CLR_BIT(TCCR0,CS00);
		    	SET_BIT(TCCR0,CS01);
		    	SET_BIT(TCCR0,CS02);
		    }
		break;
		case EX_Rise_edge:
			{
				SET_BIT(TCCR0,CS00);
				SET_BIT(TCCR0,CS01);
		        SET_BIT(TCCR0,CS02);
			}
		break;
		}
	}
	else
	{
		//do no thing
	}
}
