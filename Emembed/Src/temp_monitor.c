#include "temp_monitor.h"

uint8_t setting_temp1 = 80;
uint8_t setting_temp2 = 80;
uint8_t setting_temp3 = 80;
uint8_t setting_temp4 = 80;

void temp_sacn()
{
    uint8_t i;
    uint8_t temp;

    for ( i = 1; i < 4; i++)
    {
        temp = get_temp(i);
        if ( i == 1 )
        {
            sendstr_to_screen("n4.val=",temp);
            if ( temp < setting_temp1 )
            {
                heating_flag1 = 1;
            }else {
                heating_flag1 = 0;
            } 
        }else if ( i == 2 )
        {
            sendstr_to_screen("n5.val=",temp);
            if ( temp < setting_temp2 )
            {
                heating_flag2 = 1;
            }else {
                heating_flag2 = 0;
            } 
        }else if ( i == 3 )
        {
            sendstr_to_screen("n6.val=",temp);
            if ( temp < setting_temp3 )
            {
                heating_flag3 = 1;
            }else {
                heating_flag3 = 0;
            } 
        }else if ( i == 4 )
        {
            sendstr_to_screen("n7.val=",temp);
            if ( temp < setting_temp4 )
            {
                heating_flag4 = 1;
            }else {
                heating_flag4 = 0;
            } 
        } 
    }
}