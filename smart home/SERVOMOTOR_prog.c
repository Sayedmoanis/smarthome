#include "STD_TYPES.h"

#include "TIMER_interface.h"

#include "Map.h"
#include "SERVOMOTOR_interface.h"





void SERVOMOTOR_voidSetAngle(uint8 Copy_u8Angle)
{
	uint16 Local_u16CompVal;


	Local_u16CompVal= Map(0,180,1000,7000,Copy_u8Angle);
	TIMER1_u8SetCompareValue(TIMER1_OC1A,Local_u16CompVal);
}
