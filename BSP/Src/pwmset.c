#include "pwmset.h"

void PWM_Crl( uint8_t channel_num, uint8_t wind_num )
{
     switch(channel_num)
    {
        case PWMx_5:
            PWMB_CCR5 = 184 * wind_num;
            break;
        case PWMx_6:
            PWMB_CCR6 = 184 * wind_num;
            break;
        case PWMx_7:
            PWMB_CCR7 = 184 * wind_num;
            break;
        case PWMx_8:
            PWMB_CCR8 = 184 * wind_num;
            break;                                    
    }
}
