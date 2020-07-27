/*
 * bitwise.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Hero
 */

#ifndef BITWISE_H_
#define BITWISE_H_
#define 	SET_BIT(VAR,BIT_NO)       (VAR)|=(1<<(BIT_NO))
#define     CLR_BIT(VAR,BIT_NO)       (VAR)&=~(1<<(BIT_NO))
#define     GET_BIT(VAR,BIT_NO)       (((VAR)>>(BIT_NO))&0X01)
#define     TOG_BIT(VAR,BIT_NO)       (VAR)^=(1<<(BIT_NO))
#define     SET_PORT(VAR)             (VAR)|=0XFF;
#define     CLR_PORT(VAR)             (VAR)&=0X00;
#define     GET_PORT(VAR)             (VAR)&=0xff;
#endif /* BITWISE_H_ */
