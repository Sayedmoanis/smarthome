#include "STD_TYPES.h"
#include "ADC_interface.h"
#include "LM35_interface.h"
#include "LM35_cfg.h"
#include "LM35_prv.h"





uint16 LM35_u8GetTempInC(uint16 Copy_u8DIgital){


	uint16 Analogmv=(uint16)(((uint32)Copy_u8DIgital*5000UL)/256UL);
	uint16 temp=Analogmv/10;
	return temp;




}
