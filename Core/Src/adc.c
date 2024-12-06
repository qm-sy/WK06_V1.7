#include "adc.h"

#define ADC_POWER   0x80            //ADC电源控制位
#define ADC_START   0x40           //ADC起始控制位
#define ADC_FLAG    0x20            //ADC完成标志

/**
 * @brief ADC Init
 *
 * @param[in] 
 * 
 * @return  NULL
 * 
 * */

void ADC_Init( void )
{	
    ADC_CONTR |= ADC_POWER;     //开AD转换电源
    delay_ms(10);               //适当延时等待AD转换供电稳定

	ADCCFG    &= 0xFC;          //AD转换速度为416个时钟数转换一次
	ADCCFG    |= 0x0C;          //AD转换速度为416个时钟数转换一次
    
	ADC_CONTR &= 0xDF;          //清AD转换完成标志
		
	EADC       = 0;             //禁止ADC转换中断
	ADCCFG    |= 0x20;          //ADC转换结果ADC_RES存高4位，ADC_RESL存低8位
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
    ADC_CONTR &= 0xF0;
    ADC_CONTR |= (channel_x+11); 
    ADC_CONTR |= ADC_START;     

    /* 2, 等待ADC转换完成，关闭ADC转换                       */
    while (!(ADC_CONTR & ADC_FLAG));  
    ADC_CONTR &= 0xBF;
    ADC_CONTR &= ~ADC_FLAG; 

    /* 3, 赋值给 adc_value 作为返回值           */
    adc_value  = ADC_RESL;
    adc_value |= (ADC_RES << 8);

    return adc_value;
}



