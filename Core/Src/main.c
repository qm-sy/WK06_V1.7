#include "main.h"

void main( void )
{
    P_SW2 |= 0x80;
    GPIOInit();
    ADCInit();
    Uart1Init();
    Tim0Init();
    Tim1Init();
    Tim3Init();
    ET0Init();
    PWM5Init(); 
    led_on();    
    lcd_init();  
    ISP_data_init();
    EA = 1;

    printf("======== code start ========\r\n");  
    while (1)
    {
        /* code */
    }
    
}
