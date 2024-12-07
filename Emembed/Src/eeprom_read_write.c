#include "eeprom_read_write.h"

bit eeprom_write_flag = 0;

 
void eeprom_read_write( void )
{
    if( eeprom_write_flag == 1)
    {
        ISP_Earse( 0x0000 );

        ISP_Write( 0x0000, setting_temp1 );       //温度1
        ISP_Write( 0x0002, setting_temp2 );       //温度2
        ISP_Write( 0x0004, setting_temp3 );       //温度3
        ISP_Write( 0x0006, setting_temp4 );       //温度4

        eeprom_write_flag = 0;
    }
}

void eeprom_data_init( void )
{
    uint8_t dat = 0;

    setting_temp1 = ISP_Read( 0x0000 );
    setting_temp2 = ISP_Read( 0x0000 );
    setting_temp3 = ISP_Read( 0x0000 );
    setting_temp4 = ISP_Read( 0x0000 );
}

