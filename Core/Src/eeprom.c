#include "eeprom.h"

void ISP_Idle( void )
{
    IAP_CONTR = 0X00;
    IAP_CMD   = 0X00;
    IAP_TRIG  = 0X00;
    IAP_ADDRH = 0X80;
    IAP_ADDRL = 0X00; 
}

uint8_t ISP_Read( uint16_t addr )
{
    uint8_t dat;
    
    IAP_CONTR = 0X80;
    IAP_TPS = 12;
    IAP_CMD = 0X01;
    IAP_ADDRL = addr;
    IAP_ADDRH = addr>>8;
    
    IAP_TRIG = 0X5A;
    IAP_TRIG = 0XA5;
    
    delay_ms(10);
    
    dat = IAP_DATA;
    
    ISP_Idle();
    
    return dat;
}

void ISP_Write( uint16_t addr, uint8_t dat )
{
    IAP_CONTR = 0X80;
    IAP_TPS = 12;
    IAP_CMD = 0X02;
    IAP_ADDRL = addr;
    IAP_ADDRH = addr>>8;
    IAP_DATA = dat;
    
    IAP_TRIG = 0X5A;
    IAP_TRIG = 0XA5;
    
    delay_ms(10);
    
    ISP_Idle();
}

void ISP_Earse( uint16_t addr )
{   
    IAP_CONTR = 0X80;
    IAP_TPS = 12;
    IAP_CMD = 0X03;
    IAP_ADDRL = addr;
    IAP_ADDRH = addr>>8;
    
    IAP_TRIG = 0X5A;
    IAP_TRIG = 0XA5;
    
    delay_ms(10);
    
    ISP_Idle();
}

