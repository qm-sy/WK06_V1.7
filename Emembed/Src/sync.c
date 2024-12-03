#include "sync.h"

void sync_judge()
{
    if(sync_bit == 1)
    {
        
        if (external_24bit == 1)
        {
            power_bit = 1;
            wind_bit  = 1;
            sun_dis(DIS_ON);
        } else {
            power_bit = 0;
            wind_bit  = 0;
            sun_dis(DIS_OFF);
        }
    } else {
        power_bit = 1;
        wind_bit  = 1; 
        sun_dis(DIS_ON);
        
    }
    power_crl(power_num);
    wind_crl(wind_num);         //刷新风力和功率
}



void external24V_change_listen()
{
    static external24V_statu = 0;
    if( external24V_statu != external24_flag )
    {
        sync_judge();
        external24V_statu = external24_flag;
    }

}