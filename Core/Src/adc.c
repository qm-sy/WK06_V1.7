#include "adc.h"

#define ADC_POWER   0x80            //ADC电源控制位
#define ADC_SPEED0  0x20            //360个时钟
#define ADC_START   0x08            //ADC起始控制位
#define ADC_FLAG    0x10            //ADC完成标志

/**
 * @brief ADC Init
 *
 * @param[in] 
 * 
 * @return  NULL
 * 
 * */

void ADCInit( void )
{	
    P1ASF = 0x27;                   
    ADC_RES = 0;                    
    ADC_RESL=0;
    ADC_CONTR = ADC_POWER | ADC_SPEED0;
}

/**
 * @brief ADC口检测AD转换值函数
 *
 * @param[in] channel_x：ADC检测通道 
 * 
 * @return  ADC value ： 12bit（ H-4 L-8）
 * 
 * */

uint16_t Get_ADC12bitResult( uint8_t channel_x )	
{
    uint16_t adc_value = 0;
    /* 1, 启动ADC转换                           */
    ADC_CONTR |= (ADC_POWER | ADC_SPEED0 | ADC_START | (channel_x-1)); 

    /* 2, 等待ADC转换完成                       */
    while (!(ADC_CONTR & ADC_FLAG));  
    ADC_CONTR &= ~ADC_FLAG; 

    /* 3, 赋值给 adc_value 作为返回值           */
    adc_value  = ADC_RESL;
    adc_value |= (ADC_RES << 2);

    return adc_value;
}



