/*
	TIM0:定时器
	TIM1:加热
	TIM2:串口1
	TIM3:串口三
	TIM4:串口四
*/

#include "timer.h"

void Tim0_Init( void )         //11.0592Mhz  10ms
{
    AUXR &= 0x7F;			//定时器时钟12T模式
	TMOD &= 0xF0;			//设置定时器模式

	TL0 = 0x00;				//设置定时初始值
	TH0 = 0xDC;				//设置定时初始值

	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时

	ET0 = 1;            //打开IE-ET0，TIM0中断
}

void Tim1_Init( void )            //11.0592Mhz  10ms  16位手动装载
{   
	AUXR &= 0xBF;                //定时器时钟12T模式
	TMOD &= 0x0F;                //设置定时器模式
	TMOD |= 0x10;                //设置定时器模式   手动/自动开关
}

void Tim3_Init( void )            //10毫秒@11.0592MHz
{
	T4T3M &= 0xFD;               //定时器时钟12T模式
	T3L = 0x00;                  //设置定时初始值
	T3H = 0xDC;                  //设置定时初始值
	T4T3M |= 0x08;              //定时器3开始计时
    
    IE2 |= 0x20;                //打开IE2-ET2，TIM3中断
}

void ET0_Init( void )
{
    IT0 = 1;   //下降沿触发过零检测信号
    EX0 = 1;
}

