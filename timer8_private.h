/*
 * timer8_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Hero
 */

#ifndef TIMER8_PRIVATE_H_
#define TIMER8_PRIVATE_H_
#define OCR0                         *((volatile u8*) 0X5C)  //Output Compare Register
#define TIMSK                        *((volatile u8*) 0X59)  //Timer/Counter Interrupt Mask
#define TCCR0                        *((volatile u8*) 0X53)  //Timer/Counter Control Register
#define TCNT0                        *((volatile u8*) 0X52)  //Timer/Counter Register
#define TIFR                         *((volatile u8*) 0X58)  //Timer/Counter Interrupt Flag
#endif /* TIMER8_PRIVATE_H_ */
