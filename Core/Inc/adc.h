#ifndef __ADC_H_
#define __ADC_H_

//#include "../SYSTEM/sys.h"
#include "sys.h"

void ADCInit( void );
uint16_t Get_ADC12bitResult( uint8_t channel_x );

#endif 