#include "main.h"
#include "serial_comport.h"
#include "ntc.h"
#include "pwmset.h"
#include "screen.h"
#include "eeprom_read_write.h"
#include "wind_crl.h"

void main( void )
{
    P_SW2 |= 0x80;
    GPIO_Init();
    ADC_Init();
    Uart1_Init();
    Uart3_Init();
    Uart4_Init();
    Tim0_Init();
    Tim1_Init();
    Tim3_Init();
    
    ET0_Init();
    PWM_Init();  
    eeprom_data_init(); 
    EA = 1;

    printf("======== code start ========\r\n");  
    while (1)
    {
        receive_form_screen();
        wind_crl( PWMx_5,2);
        delay_us(1000);
        temp_sacn();
        eeprom_read_write();
    }
    
}
