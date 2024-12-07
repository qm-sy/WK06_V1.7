#include "main.h"
#include "serial_comport.h"
#include "ntc.h"
#include "pwmset.h"
#include "screen.h"
#include "eeprom_read_write.h"

void main( void )
{
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
    //     temp = (uint8_t)get_temp(1);
    //    // PWM7_Crl(5);
    //     PWM8_Crl(1);
    //     delay_ms(560);
    //     printf(" now temp is: %d \r\n",(int)temp);
        // Uart1_SendStr("t18.txt=\"cccc...\"");        
        // Uart1_Sendbyte(0xff);
        // Uart1_Sendbyte(0xff);
        // Uart1_Sendbyte(0xff);
        // receive_form_screen();
        // //temp_sacn();
        // relay = 1;
        // delay_ms(1000);
        // relay = 0;
        // delay_ms(1000);
        // OUT24 = 1;
        // //rs485();

    }
    
}
