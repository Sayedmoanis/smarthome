
#include "STD_TYPES.h"
#include <util/delay.h>
#include "ErrType.h"
#include "map.h"
#include "MOTOR_interface.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "ADC_interface.h"
#include "GIE_interface.h"
#include "TIMER_interface.h"
#include "LM35_interface.h"
#include "KPD_interface.h"
#include "CLCD_interface.h"
#include "LDR_interface.h"
#include "PWM_interface.h"
#include "SERVOMOTOR_interface.h"
#include "application.h"



void APP_voidControlLight(void)
{


	uint16 LightLevel = 0;
	CLCD_voidGoToXY(0,1);
	CLCD_u8SendString("Light Level:");
	uint8 Local_u8Counter = 8;
	while(Local_u8Counter--){

		LightLevel =  LDR_u8GetLightLevel(ADC_SINGLE_ENDED_CH7, 100);
		CLCD_voidGoToXY(12,1);
		CLCD_voidSendNumber(LightLevel);
		uint16 local_u8led =Map(0,100,0,255,LightLevel);
		DIO_u8SetPortValue(DIO_u8PORTC,local_u8led);

		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_LOW);

		_delay_ms(500);
		CLCD_voidGoToXY(0,1);
		CLCD_u8SendString(" ");
		CLCD_voidGoToXY(0,1);
		CLCD_u8SendString(" ");


	}
}



void APP_voidOpenDoor(void)
{
	TIMER1_cfg_t Local_sTimer1_Cfg = {
			.WFG_Mode=T1_FAST_PWM_TOP_ICR1,
			.OC1A_Opt = T1_OC1A_FAST_PWM_CLRON_COM_SETON_TOP,
			.OC1B_Opt = T1_OC1B_DISCONNECT,
			.Prescaler = TIMER_PRESCALER_DIVISION_8,
			.ICU_Trigger_Opt = T1_ICU_NONE,
			.ICU_Noise_State = T1_ICU_DISABLED_NOISE_CANCELER,
			.INT_State = T1_INT_DISABLED
	};




	/* PWM mode in timer1 with top value = 40000 to control the duty cycle   */
	TIMER1_u8Init(&Local_sTimer1_Cfg);
	TIMER1_u8SetTopValue(T1_ICR1_TOP,4000);

	SERVOMOTOR_voidSetAngle(89);


}



void APP_voidCloseDoor(void)
{

	TIMER1_cfg_t Local_sTimer1_Cfg = {
			.WFG_Mode=T1_FAST_PWM_TOP_ICR1,
			.OC1A_Opt = T1_OC1A_FAST_PWM_CLRON_COM_SETON_TOP,
			.OC1B_Opt = T1_OC1B_DISCONNECT,
			.Prescaler = TIMER_PRESCALER_DIVISION_8,
			.ICU_Trigger_Opt = T1_ICU_NONE,
			.ICU_Noise_State = T1_ICU_DISABLED_NOISE_CANCELER,
			.INT_State = T1_INT_DISABLED
	};




	/* PWM mode in timer1 with top value = 40000 to control the duty cycle   */
	TIMER1_u8Init(&Local_sTimer1_Cfg);
	TIMER1_u8SetTopValue(T1_ICR1_TOP,4000);

	SERVOMOTOR_voidSetAngle(20);


}

void APP_voidopenfan(void)
{
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);

	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN4,DIO_u8PIN_HIGH);


}


void APP_voidclosefan(void)
{
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);

	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN4,DIO_u8PIN_LOW);


}


uint16 ReadTemperatureFromLM35() {

	uint16 TempVal = 0;
	uint16 Local_u8out=0;
	CLCD_voidGoToXY(0,0);
	CLCD_u8SendString("Temp Val: ");

	while(1){
		ADC_u8StartConversionSynch(0,&TempVal);
		CLCD_voidGoToXY(12,0);
		Local_u8out = LM35_u8GetTempInC(TempVal);

		if(Local_u8out >= 10){
			CLCD_voidSendNumber(Local_u8out);
			CLCD_voidGoToXY(14,0);
			CLCD_u8SendString("C");
		}else{
			CLCD_voidSendNumber(Local_u8out);
			CLCD_voidGoToXY(13,0);
			CLCD_u8SendString("C");
			CLCD_voidGoToXY(14,0);
			CLCD_u8SendString(" ");

		}
		return Local_u8out;
	}

}

void ControlDCMotorByTemperature() {
	uint16 temperature = ReadTemperatureFromLM35();

	// Map the temperature to a PWM duty cycle
	uint16 dutyCycle = Map(LM35_MIN_TEMP, LM35_MAX_TEMP, PWM_MIN_DUTY_CYCLE, PWM_MAX_DUTY_CYCLE, temperature);

	PWM_u8Set(1000, dutyCycle); // period is 1000ms
}


void playmusic(void){


	while(1)
	{
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_HIGH);
		_delay_ms(2000);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_LOW);
		_delay_ms(100);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_HIGH);
		_delay_ms(2000);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_LOW);
		_delay_ms(100);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_HIGH);
		_delay_ms(2000);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_LOW);
		_delay_ms(100);

		break;
	}
}





void APP_voidLogin(void)
{
	uint8 local_u8arrid[4] = {1,2,3,4} ,local_u8arrpass[4] = {4,3,2,1} ;

	uint8 local_u8arrcheckID[4] = {1,2,3,4} , local_u8arrCheckPassword[4] = {4,3,2,1} ;

	uint8 local_u8ID = 1 , local_u8pass = 1 ;
	uint8 local_u8login = 3 ;


	CLCD_voidGoToXY(0,0);
	CLCD_u8SendString("Welcome to home");


	_delay_ms(2000);

	while(local_u8login){


		CLCD_voidSendCmd(1);

		local_u8ID = 1;
		local_u8pass = 1 ;
		CLCD_u8SendString("Enter ID : ");
		CLCD_voidGoToXY(0,1);

		uint8 local_u8keypad =1;
		uint8 local_u8counter =4;
		uint8 local_u8counterINX =0;

		while(local_u8counter)
		{
			do{
				local_u8keypad = KPD_u8GetPressedKey();

			}while(local_u8keypad == 0xff);

			local_u8arrcheckID[local_u8counterINX++] = local_u8keypad ;
			local_u8counter--;
			CLCD_voidSendNumber(local_u8keypad);

		}

		for(local_u8counter=0 ; local_u8counter<4 ; local_u8counter++)
		{
			if(local_u8arrcheckID[local_u8counter] != local_u8arrid[local_u8counter])
			{

				local_u8ID = 0 ;

			}
		}

		CLCD_voidSendCmd(1);

		CLCD_u8SendString("Enter Password:");
		CLCD_voidGoToXY(0,1);

		local_u8keypad = 1;
		local_u8counter =4;
		local_u8counterINX = 0;
		while(local_u8counter)
		{
			do{
				local_u8keypad = KPD_u8GetPressedKey();

			}while(local_u8keypad == 0xff);



			local_u8arrCheckPassword[local_u8counterINX++] =local_u8keypad ;
			local_u8counter--;

			CLCD_voidSendNumber(local_u8keypad);

		}



		for(local_u8counter=0 ; local_u8counter<4 ; local_u8counter++)
		{
			if(local_u8arrCheckPassword[local_u8counter]!=local_u8arrpass[local_u8counter])
			{

				local_u8pass = 0 ;

			}
		}

		if (local_u8ID && local_u8pass)
		{


			CLCD_voidSendCmd(1);

			CLCD_u8SendString("Welcome owner");
			_delay_ms(2000);
			CLCD_voidSendCmd(1);

			break;

		}
		else if ((local_u8ID==0) & (local_u8pass ==1))
		{

			CLCD_voidSendCmd(1);

			CLCD_u8SendString("Invalid Id ");

			local_u8login--;
		}

		else if ((local_u8ID==1) & (local_u8pass ==0))
		{

			CLCD_voidSendCmd(1);

			CLCD_u8SendString("Invalid Password");
			local_u8login--;

		}
		else if ((local_u8ID==0) & (local_u8pass ==0))
		{

			CLCD_voidSendCmd(1);

			CLCD_u8SendString("Invalid Id");

			CLCD_voidGoToXY(0,1);

			CLCD_u8SendString("Invalid Password");



			local_u8login--;

		}

		if(local_u8login)

		{
			_delay_ms(2000);

			CLCD_voidSendCmd(1);

			CLCD_u8SendString("Try Again..");
			_delay_ms(2000);
			CLCD_voidSendCmd(1);

		}


	}



}




































