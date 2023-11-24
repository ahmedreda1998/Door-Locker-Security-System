 /******************************************************************************
 *
 * Module: main Functions
 *
 * File Name: mainfunctions.h
 *
 * Description: header file for the Main Functions
 *
 * Author: Ahmed Reda
 *
 *******************************************************************************/


#ifndef MAINFUNCTIONS_H_
#define MAINFUNCTIONS_H_

#include "timer1.h"
#include "uart.h"
#include "gpio.h"
#include "keypad.h"
#include "lcd.h"
#include <avr/io.h>
#include <util/delay.h>


#define MC2_READY 0x10
#define success   0x40
#define fail      0x41
#define MC1_READY 0x11
#define motor     0x20
#define chgpass   0x21
#define done    0x15
#define lock    0x16
#define unlock  0x17
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void Enter_pass ( uint8 * pass);
uint8 array_check (uint8 * arr1, uint8 * arr2);
void Screen_1 (void);
void Screen_2 (void);
void Screen_3 (void);
void Screen_4 (void);
void Screen_5 (void);
void Screen_6 (void);
void Pass_to_MC2(uint8 * pass);
void Pass_from_MC2 (uint8* pass);
void send_status (uint8 state);
uint8 recieve_status (void);
void countSec(void);
void delaySeconds(uint8 sec);

#endif /* MAINFUNCTIONS_H_ */
