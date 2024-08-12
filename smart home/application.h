
#ifndef APPLICATION_H_
#define APPLICATION_H_

void APP_voidControlLight(void);
void APP_voidOpenDoor(void);
void APP_voidCloseDoor(void);
void APP_voidopenfan(void);
void APP_voidclosefan(void);
void APP_voidControlFanlm35(void);
void APP_voidLogin();
uint16 ReadTemperatureFromLM35() ;
void ControlDCMotorByTemperature() ;
void playmusic(void);

#define ADC_MAX_VALUE 255        // Maximum value for an 8-bit ADC
#define LM35_MAX_TEMP 150        // Maximum temperature that the LM35 can measure (in degrees Celsius)
#define LM35_MIN_TEMP 0          // Minimum temperature that the LM35 can measure (in degrees Celsius)
#define PWM_MAX_DUTY_CYCLE 1000  // Define the maximum duty cycle for PWM
#define PWM_MIN_DUTY_CYCLE 0     // Define the minimum duty cycle for PWM

#endif /* APPLICATION_H_ */
