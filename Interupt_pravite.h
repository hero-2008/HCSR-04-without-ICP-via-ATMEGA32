/*
 * Interupt_pravite.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Hero
 */

#ifndef INTERUPT_PRAVITE_H_
#define INTERUPT_PRAVITE_H_
#define   SREG                 *((volatile u8*)0x5F)
#define   MCUCR                *((volatile u8*)0x55)  //Control Register
#define   MCUCSR               *((volatile u8*)0x54)    //Control and Status Register
#define   GICR                 *((volatile u8*)0x5B)    //General Interrupt Control Register
#define   GIFR                 *((volatile u8*)0x5A)    //General Interrupt Flag Register

#endif /* INTERUPT_PRAVITE_H_ */
