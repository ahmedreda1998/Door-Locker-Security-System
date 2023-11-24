 /******************************************************************************
 *
 * Module: Timer1
 *
 * File Name: timer1.c
 *
 * Description: Source file for the Timer1 driver
 *
 * Author: Ahmed Reda
 *
 *******************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer1.h"
static volatile void(*g_callback_timer1ptr)(void) = NULL_PTR;
ISR(TIMER1_OVF_vect)
{
	if ((g_callback_timer1ptr)!= NULL_PTR)
	{
		(*g_callback_timer1ptr)();
	}
}

ISR (TIMER1_COMPA_vect)
{
	if ((g_callback_timer1ptr)!= NULL_PTR)
		{
			(*g_callback_timer1ptr)();
		}
}

void Timer1_init(const Timer1_ConfigType * Config_Ptr)
{
	if ((Config_Ptr -> mode ) == normal)
	{
		TCNT1 = Config_Ptr -> initial_value;
		TCCR1A = 0;
		TCCR1B = 0;
		TIMSK = (1<<TOIE1);
	}
	else if ((Config_Ptr -> mode ) == compare)
	{
		TCNT1 = Config_Ptr -> initial_value;
		OCR1A = Config_Ptr -> compare_value;
		TCCR1A = 0;
		TCCR1B = (1<<WGM12);
		TIMSK = (1<<OCIE1A);
	}
	TCCR1B |= (Config_Ptr -> prescaler)& 0x07;



}

void Timer1_deInit(void)
{
	TCNT1 = 0;
	OCR1A = 0;
	TCCR1A = 0;
	TCCR1B = 0;
	TIMSK = 0;
}
void Timer1_setCallBack(void(*a_ptr)(void))
{
	g_callback_timer1ptr = a_ptr;

}


