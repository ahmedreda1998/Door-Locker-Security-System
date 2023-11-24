 /******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: DC_Motor.h
 *
 * Description: header file for the DC Motor (Fan)
 *
 * Author: Ahmed Reda
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"


/**********************************************************************************
 *                             Type  Declarations                                 *
 **********************************************************************************/
typedef enum {
	STOP,CW,ACW
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* The initialisation function for the DC Motor */
void DcMotor_Init(void);

/*  the DcMotor Rotate function to start or stop the motion of the Dc Motor */
void DcMotor_Rotate (DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H_ */
