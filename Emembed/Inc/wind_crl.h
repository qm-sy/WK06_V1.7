#ifndef __WIND_CRL_H_
#define __WIND_CRL_H_

#include "pwmset.h"
#include "eeprom_read_write.h"

extern bit wind_bit;

void wind_crl( uint8_t channel_num , uint8_t wind_num );

#endif 