#include "delay.h"

/**
 * @brief ms 级延时函数
 *
 * @param[in] time 延时时间
 * 
 * @return  
 * 
 * */

void delay_ms( uint16_t time )	//@11.0592MHz
{
	uint8_t  i, j;
    for( ; time > 0; time-- )
    {
        _nop_();
        _nop_();
        _nop_();
        i = 11;
        j = 190;
        do
        {
            while (--j);
        } while (--i);
    }
}

/**
 * @brief  us 级延时函数
 *
 * @param[in] time 延时时间
 * 
 * @return  
 * 
 * */

void delay_us( uint16_t time )	//@11.0592MHz
{
    for( ; time > 0; time-- )
    {
        _nop_();
        _nop_();
        _nop_();
    }
}