/*
 * timer8_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Hero
 */

#ifndef TIMER8_INTERFACE_H_
#define TIMER8_INTERFACE_H_
///////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////Timer/Counter Control Register – TCCR0/////////////////////////////////////////////////
#define    FOC0                7        //Force Output Compare
#define    WGM00               6        //Waveform Generation Mode bit0
#define    COM01               5        //Waveform Generation Mode bit1
#define    COM00               4        //Compare Match Output Mode bit0
#define    WGM01               3        //Compare Match Output Mode bit1
#define    CS02                2        //Clock Select bit2
#define    CS01                1        //Clock Select bit1
#define    CS00                0        //Clock Select bit0
//////////////////////////////////////////////////////////////////////////////////////////////////
///////////////Timer/Counter Interrupt Mask Register – TIMSK//////////////////////////////////////

#define    OCIE0               1        //timer/Counter0 Output Compare Match Interrupt Enable
#define    TOIE0               0        //timer/Counter0 Overflow Interrupt Enable
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////Timer/Counter Interrupt Flag Register – TIFR////////////////////////////////
#define    OCF0                1        //Output Compare Flag 0
#define    TOV0                0        //timer/Counter0 Overflow Flag
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////pins//////////////////////////////////////////////////////////////////////////
#define    OC0_pin             3        //port number 3 in port B  ALWAYS OUTPUT DICRECTION  FOR WAVE FORM GENERATION
#define    TO_pin              0        //port number 0 in port B  ALWAYS INPUT DICRECTION   FOR COUNTER SCOURSE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////PRESCALER////////////////////////////////////////////////////////////////////////////////////
#define   NO_CLOCK_SCOURCE     0             //N0_PRESCALER
#define   No_prescaling        1
#define   CLK_8                2             //PRESCALER 8
#define   CLK_64               3             //PRESCALER 64
#define   CLK_256              4             //PRESCALER 256
#define   CLK_1024             5             //PRESCALER 1024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////EXTERNAL CLOCK counter/////////////////////////////////////////////////////////////////////
#define   EX_Fall_edge         0             //External clock source on T0 pin. Clock on falling edge
#define   EX_Rise_edge         1             //External clock source on T0 pin. Clock on rising edge
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////servises///////////////////////////////////////////////////////////////////////////////////////
void Enable_Timer_counter_OV();
void Enable_Counter_Output_Match();
void Select_Normal_Timer_Mode();
void Select_PWM_Phase_Correct_Mode();
void Select_Clear_Timer_Compare_Mode();
void Select_Fast_PWM_Mode();
void OC0_Normal();
void OC0_Toggle();
void OC0_Clear();
void OC0_Set();
void Select_prescaler(u8 Statuse);
void Select_CLK_Source(u8 EX_CLK);
#endif /* TIMER8_INTERFACE_H_ */
