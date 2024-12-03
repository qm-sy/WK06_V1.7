#include "led.h"

void led_on( void )
{
    LED1 = LED2 = LED3 = 1;
    LED4 = LED5 = LED6 = 1;
}

void led_off( void )
{
    LED1 = LED2 = LED3 = 0;
    LED4 = LED6 = 0;
}