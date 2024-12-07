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
    AUXR |= 0X80;		//修改计数速率，定时器时钟设置为12T模式
	
	TMOD &= 0XF0;		//清空TIM0需要配置的低四位（低四位是TIM0,高四位是TIM1）

	TH0 = 0XCD;			// TH0 高四位  TL0 低四位
	TL0 = 0XD4;			//通过计算得出的值，计算公式在下面
	
	TF0 = 0;			//清除TC0N-TF0  中断溢出标志，溢出后自动置1，CPU响应中断后置硬件清0
	TR0 = 1;			//TCON-TR0  TIM0开始计数启动

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

