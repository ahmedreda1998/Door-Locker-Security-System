 /******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: buzzer.c
 *
 * Description: Source file for the Buzzer driver
 *
 * Author: Ahmed Reda
 *
 *******************************************************************************/
#include "buzzer.h"

void Buzzer_init()
{
	GPIO_setupPinDirection(buzzer_port, buzzer_pin, PIN_OUTPUT);
	GPIO_writePin(buzzer_port, buzzer_pin, LOGIC_LOW);


}

void Buzzer_on(void)
{

	GPIO_writePin(buzzer_port, buzzer_pin, LOGIC_HIGH);


}
void Buzzer_off(void)
{


	GPIO_writePin(buzzer_port, buzzer_pin, LOGIC_LOW);


}
