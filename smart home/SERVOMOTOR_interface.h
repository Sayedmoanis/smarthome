#ifndef SERVOMOTOR_INTERFACE_H
#define SERVOMOTOR_INTERFACE_H


/*to operate servo motor you should set a PWM signal have the Following  characteristic :

 * 																					1- Period time = 20msec
 * 																					2- Duty Cycle 'ON Time'
 * 																					   1msec------>0 deg
 * 																					   2msec------>180 deg
 **/


void SERVOMOTOR_voidSetAngle(uint8 Copy_u8Angle);

#endif
