/*
 * DIO_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Hero
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#define HIGH           1
#define LOW            0
#define OUTPUT         1
#define INPUT          0
#define PORT_A         0
#define PORT_B         1
#define PORT_C         2
#define PORT_D         3
#define DIO_PIN_0      0
#define DIO_PIN_1      1
#define DIO_PIN_2      2
#define DIO_PIN_3      3
#define DIO_PIN_4      4
#define DIO_PIN_5      5
#define DIO_PIN_6      6
#define DIO_PIN_7      7
/**************************************orders****************************************/
void Set_Pin_direction(u8 port_id,u8 pin_id,u8 pin_direction);
void Set_Pin_val(u8 port_id,u8 pin_id,u8 pin_val);
u8 GET_pin_val(u8 port_id,u8 pin_id);
void Toggel_pin(u8 port_id,u8 pin_id);
void SET_PORT_DIR(u8 port_id ,u8 port_dir);
void GIVE_PORT_VAL(u8 port_id ,u8 GIVEN_VAL);
void SET_PORT_VAL(u8 port_id ,u8 port_val);
#endif /* DIO_INTERFACE_H_ */
