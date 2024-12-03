#include "preheating.h"

void temp_listen()
{   
    static uint8_t temp; 

    temp = (uint8_t)get_temp(6);
    if( temp >= temp_num )
    {
        alarm_dis(DIS_ON);
        cooling_fan = 1;
        buzzer = temp_blink_flag;
    } else {
            alarm_dis(DIS_OFF);
            cooling_fan = 0;
            buzzer = 1;
    }
}