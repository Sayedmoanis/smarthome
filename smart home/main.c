/*
 * main.c
 *
 *  Created on: Jul 27, 2024
 *      Author: elsayed moanis
 */

#include "STD_TYPES.h"
#include <util/delay.h>
#include "map.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "ADC_interface.h"
#include "GIE_interface.h"
#include "TIMER_interface.h"

#include "KPD_interface.h"
#include "CLCD_interface.h"
#include "LDR_interface.h"
#include "application.h"

void main(void) {
	uint8 Local_u8PressedKey = 1;
	uint8 continueProgram = 1;

	PORT_voidInit();
	CLCD_voidInit();
	ADC_voidInit();
	GIE_voidEnableGlobal();
	APP_voidLogin();

	while (continueProgram) {
		CLCD_voidSendCmd(1); // Clear the screen
		CLCD_u8SendString("enter 1-9");
		_delay_ms(1000);

		// Wait for a valid key press
		do {
			Local_u8PressedKey = KPD_u8GetPressedKey();
		} while (Local_u8PressedKey == 0xff);

		CLCD_voidSendCmd(1); // Clear the screen

		// Execute the selected operation using if statements
		if (Local_u8PressedKey == 1) {
			CLCD_u8SendString("open led");
			DIO_u8SetPortValue(DIO_u8PORTC, DIO_u8PORT_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN5, DIO_u8PIN_LOW);
		} else if (Local_u8PressedKey == 2) {
			CLCD_u8SendString("close led");
			DIO_u8SetPortValue(DIO_u8PORTC, DIO_u8PORT_LOW);
		} else if (Local_u8PressedKey == 3) {
			CLCD_u8SendString("control light");
			DIO_u8SetPortValue(DIO_u8PORTC, DIO_u8PORT_HIGH);
			APP_voidControlLight();
		} else if (Local_u8PressedKey == 4) {
			APP_voidOpenDoor();
			CLCD_u8SendString("open door");
		} else if (Local_u8PressedKey == 5) {
			APP_voidCloseDoor();
			CLCD_u8SendString("close door");
		} else if (Local_u8PressedKey == 6) {
			CLCD_u8SendString("open fan");
			APP_voidopenfan();
		} else if (Local_u8PressedKey == 7) {
			CLCD_u8SendString("close fan");
			APP_voidclosefan();
		} else if (Local_u8PressedKey == 8) {
			CLCD_voidGoToXY(0, 1);
			CLCD_u8SendString("control fan");
			ControlDCMotorByTemperature();
		} else if (Local_u8PressedKey == 9) {
			CLCD_voidGoToXY(0, 0);
			CLCD_u8SendString("play music");
			playmusic();
		}else if (Local_u8PressedKey == 10) {
			CLCD_voidGoToXY(0, 1);
			CLCD_u8SendString("control fan");
			ControlDCMotorByTemperature();
		}

		else {
			CLCD_u8SendString("Invalid input");
		}

		_delay_ms(4000);
		CLCD_voidSendCmd(1); // Clear the screen

		// Ask user if they want to continue or end
		CLCD_u8SendString("1: Continue  0: End");

		// Wait for a valid key press (1 or 0)
		do {
			Local_u8PressedKey = KPD_u8GetPressedKey();
		} while (Local_u8PressedKey != 1 && Local_u8PressedKey != 0);

		if (Local_u8PressedKey == 0) {
			continueProgram = 0; // End the program
		}
	}

	CLCD_voidSendCmd(1); // Clear the screen
	CLCD_u8SendString("Program ended");
	DIO_u8SetPortValue(DIO_u8PORTC, DIO_u8PORT_LOW); // Turn off LED
	APP_voidclosefan(); // Turn off fan
	APP_voidCloseDoor(); // Close door
	DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN5, DIO_u8PIN_LOW); //close music

	_delay_ms(5000);
}
