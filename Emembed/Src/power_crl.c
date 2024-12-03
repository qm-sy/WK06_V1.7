#include "power_crl.h"

bit power_bit = 0;

void power_crl( uint8_t power_num )
{ 
    if(power_bit==1)
    {
        ET1 = 1;
    }
    else
    {
        ET1 = 0;
    }
    
    phase_shift_time = power_num * 64 + 58400;
}
