#include "pwmset.h"

void PWM7_Crl( uint8_t num )
{
    PWMB_CCR7 = 184 * num;
}

void PWM8_Crl( uint8_t num )
{
    PWMB_CCR6 = 184 * num;
}
