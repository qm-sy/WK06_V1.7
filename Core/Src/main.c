#include "main.h"
#include "serial_comport.h"
#include "ntc.h"
#include "pwmset.h"

void main( void )
{
    uint8_t temp = 0;

    P_SW2 |= 0x80;
    GPIO_Init();
    ADC_Init();
    Uart1_Init();
    Uart4_Init();
    Tim0_Init();
    Tim1_Init();
    Tim3_Init();
    
    ET0_Init();
    PWM_Init();  
    
    EA = 1;

    printf("======== code start ========\r\n");  
    while (1)
    {
        temp = (uint8_t)get_temp(1);
       // PWM7_Crl(5);
        PWM8_Crl(1);
        delay_ms(560);
        printf(" now temp is: %d \r\n",(int)temp);
        //rs485();
    }
    
}
