#include "wind_crl.h"

bit wind_bit = 0;

void wind_crl( uint8_t wind_num )
{
    if(wind_bit == 1)       
    {
        switch(wind_num)
        {
            case 0:
                PWMStop();
                break;
            
            case 1:
                PWMSet(2000);
                break;
            
            case 2:
                PWMSet(2400);
                break;
            
            case 3:
                PWMSet(2800);
                break;
            
            case 4:
                PWMSet(3200);
                break;
            
            case 5:
                PWMSet(3600);
                break;
            
            case 6:
                PWMSet(4000);
                break;
        }
        
    } else {
        PWMStop();
    }
}
