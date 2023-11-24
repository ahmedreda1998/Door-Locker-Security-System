/******************************************************************************
 *
 * Module: Main Functions
 *
 * File Name: mainfunctions.c
 *
 * Description: source file for the  Main Functions
 *
 * Author: Ahmed Reda
 *
 *******************************************************************************/
#include "mainfunctions.h"
static volatile uint8 g_sec = 0;

uint8 array_check (uint8 * arr1, uint8 * arr2)
{
	uint8 i;
	for (i=0;i<=4;i++)
	{
		if (arr1[i]!=arr2[i])
		{
			return 0;
		}
	}
	return 1;
}

void Pass_from_MC1 (uint8 * pass)
{
	uint8 i;
	UART_sendByte(MC2_READY);
	for (i=0;i<=4;i++)
	{
		pass[i]= UART_recieveByte();
	}
}
void Pass_to_MC1(uint8 * pass)
{
	uint8 i;
	while(UART_recieveByte() != MC1_READY){}
	for (i=0;i<=4;i++)
	{
		UART_sendByte(pass[i]);
	}

}
void send_status (uint8 state)
{
	while(UART_recieveByte() != MC1_READY){}
	UART_sendByte(state);
}

 uint8 recieve_status (void)
{
	uint8 state = 0;
	UART_sendByte(MC2_READY);
	state= UART_recieveByte();
	return state;
}

void Open_door (void)
{

	DcMotor_Rotate (CW,100);
	send_status(unlock);
	delaySeconds(15);
	DcMotor_Rotate (STOP,0);
	delaySeconds(3);
	send_status(lock);
	DcMotor_Rotate (ACW,100);
	delaySeconds(15);
	DcMotor_Rotate (STOP,0);
}



void save_EEPROM (uint8 * pass)
{
	uint8 i;
		for (i=0;i<=4;i++)
		{
			EEPROM_writeByte(0x0311+i,pass[i]);
		}


}


void load_EEPROM (uint8 * pass)
{
	uint8 i;
	for (i=0;i<=4;i++)
	{
		EEPROM_readByte(0x0311+i,&pass[i]);
	}
}
void countSec(void)
{
	g_sec++;
}
void delaySeconds(uint8 sec)
{
	/* setting the callBack function to count seconds */
	Timer1_setCallBack(countSec);
	/* timer1 configurations to count sec per interrupt */
	Timer1_ConfigType timer1_config = {0,468748,F_CPU_1024,compare};
	Timer1_init(&timer1_config);
	while(g_sec < sec);
	g_sec = 0;
	Timer1_deInit();

}


void Buzzer (void)
{
	Buzzer_on();
	delaySeconds(60);
	Buzzer_off();

}
