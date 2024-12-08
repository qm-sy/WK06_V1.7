#include "pwm.h"

void PWM_Init( void )
{
	// P_SW2 |= 0X80;  
	
    // PWMB_PS |= 0x00;            //高级 PWM 通道输出脚选择位  C7PS:00-P2.2  C8PS:00-P2.3
    
    // PWMB_CCER2 = 0x00;          //写 CCMRx 前必须先清零 CCxE 关闭通道
    // PWMB_CCMR3 = 0x70;          //输入捕获n滤波器选择 PWM7
    // PWMB_CCMR4 = 0x70;          //输入捕获n滤波器选择 PWM8
    // PWMB_CCER2 = 0x11;          //配置通道PWM7 & PWM8 输出使能和极性 

    // PWMB_ARR = 0x0452;          //设置自动重装载寄存器值
                 
    // PWMB_PSCR = 0X0000;         //设置频率   频率越大 波形越平滑
    // PWMB_CCR7 = 0x012C;         //设置占空比
    // PWMB_CCR8 = 0x012C;         //设置占空比

    // PWMB_ENO |= 0x50;           //使能 PWM7 & PWM8 输出

//    PWMB_PS &= 0x3F;            //高级 PWM 通道输出脚选择位  选择 PWM8_1 P2.3通道
//    
//    PWMB_CCER2 = 0x00;          //写 CCMRx 前必须先清零 CCxE 关闭通道
//    PWMB_CCMR4 = 0x70;          //通道模式配置  选择PWM模式2
//    PWMB_CCER2 = 0x10;          //配置通道输出使能和极性 

//    PWMB_ARR = 0x0452;          //设置自动重装载寄存器值
//                 
//    PWMB_PSCR = 0X0008;         //设置频率   频率越大 波形越平滑
//    PWMB_CCR8 = 0x012C;         //设置占空比

//    PWMB_ENO |= 0x40;           //使能 PWM8 输出

//    PWMB_BKR = 0x80;            //使能主输出
//    PWMB_CR1 |= 0x01;           //将CEN2位置1，开始计时       


    PWMB_PS &= 0x00;            //高级 PWM 通道输出脚选择位  选择 PWM8_1 P2.3通道
    
    PWMB_CCER1 = 0x00;          //写 CCMRx 前必须先清零 CCxE 关闭通道
    PWMB_CCMR2 = 0x70;          //通道模式配置  选择PWM模式2
    PWMB_CCER1 = 0x10;          //配置通道输出使能和极性 

    PWMB_ARR = 0x0452;          //设置自动重装载寄存器值
                 
    PWMB_PSCR = 0X0008;         //设置频率   频率越大 波形越平滑
    PWMB_CCR6 = 0x012C;         //设置占空比

    PWMB_ENO |= 0x04;           //使能 PWM8 输出

    PWMB_BKR = 0x80;            //使能主输出
    PWMB_CR1 |= 0x01;           //将CEN2位置1，开始计时    
    
    
//     PWMB_PS&=0x00;            //高级 PWM 通道输出脚选择位  选择 PWM8_1 P2.3通道  

//     PWMB_CCER1=0x00;          //写 CCMRx 前必须先清零 CCxE 关闭通道  
//     PWMB_CCMR2=0x70;          //通道模式配置  选择PWM模式2  
//     PWMB_CCER1=0x10;          //配置通道输出使能和极性   
//      
//     PWMB_ARR=0x0452;          //设置自动重装载寄存器值  
//     
//     PWMB_PSCR=0X0008;         //设置频率   频率越大 波形越平滑  
//     PWMB_CCR6=0x012C;         //设置占空比  
//      
//     PWMB_ENO|=0x04;           //使能 PWM8 输出  
//      
//     PWMB_BKR=0x80;            //使能主输出  
//     PWMB_CR1|=0x01;           //将CEN2位置1，开始计时
}

