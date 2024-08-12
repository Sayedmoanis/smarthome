
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


void ADC_voidInit(void);


uint8 ADC_u8StartConversionSynch(uint8 Copy_u8Channel, uint16 *Copy_pu16Result);

uint16 ADC_u8GetChannelReading(uint8 Copy_u8Channel);

/*To operate this function should Enable GLobal Interrupt*/
uint8 ADC_u8StartConversionAsynch(uint8 Copy_u8Channel, uint16 *Copy_pu16Result,  void (*Copy_pvNotificationFunc)());

/*Analog Channel and Gain Selection (SINGLE_ENDE Bits)Options:-  */
/*
 1-   ADC_u8SINGLE_ENDED_ADC0
 2-   ADC_u8SINGLE_ENDED_ADC1
 3-   ADC_u8SINGLE_ENDED_ADC2
 4-   ADC_u8SINGLE_ENDED_ADC3
 5-   ADC_u8SINGLE_ENDED_ADC4
 6-   ADC_u8SINGLE_ENDED_ADC5
 7-   ADC_u8SINGLE_ENDED_ADC6
 8-   ADC_u8SINGLE_ENDED_ADC7
*/



#define ADC_SINGLE_ENDED_CH0            0u
#define ADC_SINGLE_ENDED_CH1            1u
#define ADC_SINGLE_ENDED_CH2            2u
#define ADC_SINGLE_ENDED_CH3            3u
#define ADC_SINGLE_ENDED_CH4            4u
#define ADC_SINGLE_ENDED_CH5            5u
#define ADC_SINGLE_ENDED_CH6            6u
#define ADC_SINGLE_ENDED_CH7            7u


/* Interrupt Pin direction must be input */

#endif
