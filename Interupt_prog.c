/*
 * Interupt_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Hero
 */
#include"types.h"
#include"bitwise.h"
#include"Interupt_pravite.h"
#include"Interupt_interface.h"
void Inti_interupt_0()
{
	SREG|=(1<<I);
	GICR|=(1<<INT0);
}
void Inti_interupt_1()
{
	SREG|=(1<<I);
	GICR|=(1<<INT1);
}
void Inti_interupt_2()
{
	SREG|=(1<<I);
	GICR|=(1<<INT2);
}
void Setup_interupt_low_level_INT0()
{
	CLR_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
}
void Setup_interupt_Any_logical_change_INT0()
{
	SET_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
}
void Setup_interupt_falling_edge_INT0()
{
	CLR_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
}
void Setup_interupt_rising_edge_INT0()
{
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
}
////////
void Setup_interupt_low_level_INT1()
{
	CLR_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
}
void Setup_interupt_Any_logical_change_INT1()
{
	SET_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
}
void Setup_interupt_falling_edge_INT1()
{
	CLR_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
}
void Setup_interupt_rising_edge_INT1()
{
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
}
void Setup_interupt_INT2()
{
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
}
u8 Get_interupt_0()
{
	u8 result0;
	result0=GET_BIT(GICR,INF0);
	return result0;
}
u8 Get_interupt_1()
{
	u8 result1;
	result1=GET_BIT(GICR,INF1);
	return result1;
}
u8 Get_interupt_2()
{
	u8 result2;
	result2=GET_BIT(GICR,INF2);
	return result2;
}
