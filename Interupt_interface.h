/*
 * Interupt_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Hero
 */

#ifndef INTERUPT_INTERFACE_H_
#define INTERUPT_INTERFACE_H_
/////INT0      pin NO     D2
/////INT1      pin NO     D2
/////INT2      pin NO     D2
/////ISR(INT0_vect)
//////////////////SREG//////////////////////////////////////////////////////////////////////
#define      I                7
////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////MCU Control Register – MCUCR//////////////////////////////////////////
#define      ISC00            0          //Sense Control 1 for INT0
#define      ISC01            1          //Sense Control 2 for INT0
#define      ISC10            2          //Sense Control 1 for INT1
#define      ISC11            2          //Sense Control 2 for INT1
////////////////////////////////////////////////////////////////////////////////////////////
///////////////////MCU Control and Status Register – MCUCSR/////////////////////////////////
#define      ISC2             6          //Sense Control 1 for INT2
////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////General Interrupt Control Register – GICR//////////////////////////
#define      INT1             7          //External Interrupt Request 1 Enable
#define      INT0             6          //External Interrupt Request 0 Enable
#define      INT2             5          //External Interrupt Request 2 Enable
///////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////General Interrupt Flag Register – GIFR///////////////////////
#define      INF1             7          //External Interrupt Flag 1
#define      INF0             6          //External Interrupt Flag 0
#define      INF2             5          //External Interrupt Flag 2
///////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////Servises/////////////////////////////////////////////////
void Inti_interupt_0();
void Inti_interupt_1();
void Inti_interupt_2();
void Setup_interupt_low_level_INT0();
void Setup_interupt_Any_logical_change_INT0();
void Setup_interupt_falling_edge_INT0();
void Setup_interupt_rising_edge_INT0();
void Setup_interupt_low_level_INT1();
void Setup_interupt_Any_logical_change_INT1();
void Setup_interupt_falling_edge_INT1();
void Setup_interupt_rising_edge_INT1();
void Setup_interupt_INT2();
u8 Get_interupt_0();
u8 Get_interupt_1();
u8 Get_interupt_2();
#endif /* INTERUPT_INTERFACE_H_ */
