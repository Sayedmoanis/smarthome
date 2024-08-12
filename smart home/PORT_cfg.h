#ifndef PORT_CFG_H
#define PORT_CFG_H

/*Configure the MCU Pins direction, options :  1- INPUT
											   2- OUTPUT		*/
#define PORTA_PIN0_DIR           INPUT    //lm35 pin
#define PORTA_PIN1_DIR           OUTPUT   //lcd
#define PORTA_PIN2_DIR           OUTPUT   //lcd
#define PORTA_PIN3_DIR           OUTPUT   //lcd
#define PORTA_PIN4_DIR           OUTPUT   //lcd
#define PORTA_PIN5_DIR           OUTPUT   //lcd
#define PORTA_PIN6_DIR           OUTPUT   //lcd
#define PORTA_PIN7_DIR           INPUT    //LDR Pin

#define PORTB_PIN0_DIR           OUTPUT
#define PORTB_PIN1_DIR           INPUT
#define PORTB_PIN2_DIR           INPUT
#define PORTB_PIN3_DIR           OUTPUT  //DC Motor Pin
#define PORTB_PIN4_DIR           INPUT   //rows keypad
#define PORTB_PIN5_DIR           INPUT   //rows keypad
#define PORTB_PIN6_DIR           INPUT   //rows keypad
#define PORTB_PIN7_DIR           INPUT   //rows keypad

#define PORTC_PIN0_DIR           OUTPUT
#define PORTC_PIN1_DIR           OUTPUT
#define PORTC_PIN2_DIR           OUTPUT
#define PORTC_PIN3_DIR           OUTPUT
#define PORTC_PIN4_DIR           OUTPUT
#define PORTC_PIN5_DIR           OUTPUT
#define PORTC_PIN6_DIR           OUTPUT
#define PORTC_PIN7_DIR           OUTPUT

#define PORTD_PIN0_DIR           INPUT
#define PORTD_PIN1_DIR           OUTPUT //buzzer
#define PORTD_PIN2_DIR           OUTPUT //col keypad
#define PORTD_PIN3_DIR           OUTPUT //col keypad
#define PORTD_PIN4_DIR           OUTPUT //col keypad
#define PORTD_PIN5_DIR           OUTPUT //col keypad  //Servomotor Pin
#define PORTD_PIN6_DIR           OUTPUT
#define PORTD_PIN7_DIR           INPUT


/*Configure the MCU pins intitial value, in case of input direction, options:   1- FLOATING
																			    2- PULLED_UP
																				
										, in case of output direction, options: 1- LOW
																				2- HIGH  */
#define PORTA_PIN0_INIT_VAL           FLOATING
#define PORTA_PIN1_INIT_VAL           FLOATING
#define PORTA_PIN2_INIT_VAL           FLOATING
#define PORTA_PIN3_INIT_VAL           FLOATING
#define PORTA_PIN4_INIT_VAL           FLOATING
#define PORTA_PIN5_INIT_VAL           FLOATING
#define PORTA_PIN6_INIT_VAL           FLOATING
#define PORTA_PIN7_INIT_VAL           FLOATING

#define PORTB_PIN0_INIT_VAL           LOW
#define PORTB_PIN1_INIT_VAL           LOW
#define PORTB_PIN2_INIT_VAL           LOW
#define PORTB_PIN3_INIT_VAL           LOW         //dc motor
#define PORTB_PIN4_INIT_VAL           PULLED_UP   //rows
#define PORTB_PIN5_INIT_VAL           PULLED_UP   //rows
#define PORTB_PIN6_INIT_VAL           PULLED_UP   //rows
#define PORTB_PIN7_INIT_VAL           PULLED_UP   //rows

#define PORTC_PIN0_INIT_VAL           FLOATING
#define PORTC_PIN1_INIT_VAL           FLOATING
#define PORTC_PIN2_INIT_VAL           FLOATING
#define PORTC_PIN3_INIT_VAL           FLOATING
#define PORTC_PIN4_INIT_VAL           FLOATING
#define PORTC_PIN5_INIT_VAL           FLOATING
#define PORTC_PIN6_INIT_VAL           FLOATING
#define PORTC_PIN7_INIT_VAL           FLOATING

#define PORTD_PIN0_INIT_VAL           LOW
#define PORTD_PIN1_INIT_VAL           FLOATING
#define PORTD_PIN2_INIT_VAL           LOW   //col keypad
#define PORTD_PIN3_INIT_VAL           LOW   //col keypad
#define PORTD_PIN4_INIT_VAL           LOW   //col keypad
#define PORTD_PIN5_INIT_VAL           LOW   //col keypad
#define PORTD_PIN6_INIT_VAL           FLOATING  //Servomotor Pin
#define PORTD_PIN7_INIT_VAL           LOW

#endif
