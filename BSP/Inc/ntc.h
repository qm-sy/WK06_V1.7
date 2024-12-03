#ifndef __NTC_H_
#define __NTC_H_

#include "sys.h"

uint8_t LookupTable( uint16_t *temp_tab, uint8_t tab_num, uint16_t adc_val );
uint16_t get_temp( uint8_t channle_x );

#endif