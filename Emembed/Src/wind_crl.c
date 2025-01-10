#include "wind_crl.h"

bit wind_bit = 0;

void wind_crl( uint8_t channel_num , uint8_t wind_num )
{
    PWM_Crl( channel_num, wind_num );
    eeprom_write_flag = 1;
}
