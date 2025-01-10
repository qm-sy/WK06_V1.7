#include "pwm.h"

void PWM_Init( void )
{
	P_SW2     |= 0X80;  
	
    PWMB_PS   |= 0x00;          //高级 PWM 通道 PWM5-P2.0  PWM6-P2.1N PWM7-P2.2  PWM8-P2.3
    
    PWMB_CCER1 = 0x00;          //清零CC5E、CC6E关闭通道
    PWMB_CCER2 = 0x00;          //清零CC7E、CC8E关闭通道

    PWMB_CCMR1 = 0X70;          //输入捕获n滤波器选择 PWM5
    PWMB_CCMR2 = 0X70;          //输入捕获n滤波器选择 PWM6
    PWMB_CCMR3 = 0x70;          //输入捕获n滤波器选择 PWM7
    PWMB_CCMR4 = 0x70;          //输入捕获n滤波器选择 PWM8
    
    PWMB_CCER1 = 0x11;          //配置通道PWM5 & PWM6 输出使能和极性 
    PWMB_CCER2 = 0x11;          //配置通道PWM7 & PWM8 输出使能和极性 

    PWMB_ARR   = 0x0452;        //设置自动重装载寄存器值
                 
    PWMB_PSCR  = 0x0008;        //设置频率   频率越大 波形越平滑  1ms
    PWMB_CCR5  = 0x012C;        //设置PWM5占空比
    PWMB_CCR6  = 0x012C;        //设置PWM6占空比
    PWMB_CCR7  = 0x012C;        //设置PWM7占空比
    PWMB_CCR8  = 0x012C;        //设置PWM8占空比

    PWMB_ENO  |= 0x55;          //使能 PWM5 & PWM6 & PWM7 & PWM8 输出

    PWMB_BKR   = 0x80;          //使能主输出
    PWMB_CR1  |= 0x01;          //将CEN2位置1，开始计时        
}

