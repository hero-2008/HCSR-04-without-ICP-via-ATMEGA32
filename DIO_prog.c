/*
 * DIO_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Hero
 */
#include"types.h"
#include"bitwise.h"
#include"DIO_private.h"
#include"DIO_interface.h"
void Set_Pin_direction(u8 port_id,u8 pin_id,u8 pin_direction)
{
	if (port_id<=PORT_D && pin_id<=DIO_PIN_7)
	{
       if(pin_direction==OUTPUT)
       {
    	   switch(port_id)
    	   {
    	   case PORT_A:  SET_BIT(DDRA_REG,pin_id);  break;
    	   case PORT_B:  SET_BIT(DDRB_REG,pin_id);  break;
    	   case PORT_C:  SET_BIT(DDRC_REG,pin_id);  break;
    	   case PORT_D:  SET_BIT(DDRD_REG,pin_id);  break;
    	   }
       }
       else if (pin_direction==INPUT)
       {
    	   switch(port_id)
    	   {
    	   case PORT_A:  CLR_BIT(DDRA_REG,pin_id);  break;
    	   case PORT_B:  CLR_BIT(DDRB_REG,pin_id);  break;
    	   case PORT_C:  CLR_BIT(DDRC_REG,pin_id);  break;
    	   case PORT_D:  CLR_BIT(DDRD_REG,pin_id);  break;
    	   }
       }
	}
	else
	{
		/*do nothing*/
	}
}
void Set_Pin_val(u8 port_id,u8 pin_id,u8 pin_val)
{
	if(port_id<=PORT_D && pin_id<=DIO_PIN_7 )
	{
		if(pin_val==HIGH)
		{
			switch(port_id)
			{
			case PORT_A: SET_BIT(PORTA_REG,pin_id);  break;
			case PORT_B: SET_BIT(PORTB_REG,pin_id);  break;
			case PORT_C: SET_BIT(PORTC_REG,pin_id);  break;
			case PORT_D: SET_BIT(PORTD_REG,pin_id);  break;
			}
		}
		else if(pin_val==LOW)
		{
		    switch(port_id)
			 {
			    case PORT_A:  CLR_BIT(PORTA_REG,pin_id);  break;
			    case PORT_B:  CLR_BIT(PORTB_REG,pin_id);  break;
			    case PORT_C:  CLR_BIT(PORTC_REG,pin_id);  break;
			    case PORT_D:  CLR_BIT(PORTD_REG,pin_id);  break;
		    }
	}
    }
}
u8 GET_pin_val(u8 port_id,u8 pin_id)
{
	u8 result;
	if (port_id<=PORT_D && pin_id<=DIO_PIN_7)
	{
		switch(port_id)
		{
		case PORT_A: result=GET_BIT(PINA_REG,pin_id); break;
		case PORT_B: result=GET_BIT(PINB_REG,pin_id); break;
		case PORT_C: result=GET_BIT(PINC_REG,pin_id); break;
		case PORT_D: result=GET_BIT(PIND_REG,pin_id); break;
		}
	}
	return result;
}
void Toggel_pin(u8 port_id,u8 pin_id)
{
	if(port_id<=PORT_D && pin_id<=DIO_PIN_7)
	{
		switch(port_id)
		{
		case PORT_A: TOG_BIT(PORTA_REG,pin_id); break;
		case PORT_B: TOG_BIT(PORTB_REG,pin_id); break;
		case PORT_C: TOG_BIT(PORTC_REG,pin_id); break;
		case PORT_D: TOG_BIT(PORTD_REG,pin_id); break;
		}
	}
}
void GIVE_PORT_VAL(u8 port_id,u8 GIVEN_VAL )
{
	if(port_id<=PORT_D)
	{
		switch(port_id)
		{
		    case PORT_A: PORTA_REG=GIVEN_VAL; break;
		    case PORT_B: PORTB_REG=GIVEN_VAL; break;
		    case PORT_C: PORTC_REG=GIVEN_VAL; break;
		    case PORT_D: PORTD_REG=GIVEN_VAL; break;
		}
	}
	else
	{
		/*do no thing*/
	}
}
void SET_PORT_DIR(u8 port_id ,u8 port_dir)
{
	if(port_id<=PORT_D)
	{
		if(port_dir==OUTPUT)
		{
			switch(port_id)
			{
			   case PORT_A: SET_PORT(DDRA_REG); break;
			   case PORT_B: SET_PORT(DDRB_REG); break;
			   case PORT_C: SET_PORT(DDRC_REG); break;
			   case PORT_D: SET_PORT(DDRD_REG); break;
			}
		}
		else if(port_dir==INPUT)
		{
			switch(port_id)
			{
    	       case PORT_A: CLR_PORT(DDRA_REG); break;
    	   	   case PORT_B: CLR_PORT(DDRB_REG); break;
    	   	   case PORT_C: CLR_PORT(DDRC_REG); break;
    	   	   case PORT_D: CLR_PORT(DDRD_REG); break;
			}
		}
	}
	else
	{
		/*do nothing*/
	}
}
void SET_PORT_VAL(u8 port_id ,u8 port_val)
{
	if(port_id<=PORT_D)
	{
		if(port_val==HIGH)
		{
			switch(port_id)
			{
			    case PORT_A: SET_PORT(PORTA_REG); break;
				case PORT_B: SET_PORT(PORTB_REG); break;
				case PORT_C: SET_PORT(PORTC_REG); break;
				case PORT_D: SET_PORT(PORTD_REG); break;
			}
		}
		else if (port_val==LOW)
		{
			switch(port_id)
				{
			          case PORT_A: CLR_PORT(PORTA_REG); break;
			          case PORT_B: CLR_PORT(PORTB_REG); break;
			          case PORT_C: CLR_PORT(PORTC_REG); break;
			          case PORT_D: CLR_PORT(PORTD_REG); break;
				}
		}
	}
}


