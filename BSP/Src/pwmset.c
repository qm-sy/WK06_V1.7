#include "pwmset.h"

void PWMSet( uint16_t num )
{
    PWMStart();
    PWM5T2 = num;
}

void PWMStart (void )
{
    PWMCR = 0X88;
}