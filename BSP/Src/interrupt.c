#include "interrupt.h"

//static bit zero_flag = 0;       //外部中断（过零检测）et0响应flag 响应赋值为1
bit busy_flag = 0;
bit rev_end;             //数据包发送完毕标志
uint8_t rev_buf[128];    //SBUF RI缓冲区
uint16_t rev_timeout;    //接收超时
uint8_t rev_bytenum;     //接收计数

//uint16_t phase_shift_time = 58400;

void Uart1Isr() interrupt 4 
{   
    if( SCON & TI )
    {
        SCON &= ~TI;
        busy_flag = 0;
    }
    
    if(SCON & RI)
    {
        SCON &= ~RI;
        if ( !rev_end )
        {
            if (rev_bytenum > 128)
            {
                rev_bytenum = 0;
            }
            rev_buf[rev_bytenum] = SBUF;  //将SBUF内的数据写入缓冲区
            rev_bytenum++;
        }
        rev_timeout = 50;
    }
}

void ET0ISR(void) interrupt 0 
{
    // tempchannel1 = tempchannel2 = tempchannel3 = 1;    
    // /*延时移相                  */
    // TL1 = TIM1;			    	//设置定时初始值
	// TH1 = TIM1>>8;				//设置定时初始值

    // zero_flag = 1;
    
    // TR1 = 1;			    	//定时器1开始计时      
    // ET1 = 1; 
}

void Tim1Isr(void) interrupt 3 
{

    // if((zero_flag == 1)&&(power_bit == 1))
    // {
    //     switch(channel_num)
    //     {
    //         case 1: {tempchannel1=0; tempchannel2=1; tempchannel3=1;}break;
    //         case 2: {tempchannel1=1; tempchannel2=0; tempchannel3=1;}break;
    //         case 3: {tempchannel1=1; tempchannel2=1; tempchannel3=0;}break;
    //         case 4: {tempchannel1=0; tempchannel2=0; tempchannel3=1;}break;
    //         case 5: {tempchannel1=1; tempchannel2=0; tempchannel3=0;}break;
    //         case 6: {tempchannel1=0; tempchannel2=1; tempchannel3=0;}break;
    //         case 7: {tempchannel1=0; tempchannel2=0; tempchannel3=0;}break;
    //     }
    //         /*1.发送一个10us的脉冲                */
    //         zero_flag = 0; 

    //         TL1 = 0xF7;				
    //         TH1 = 0xFF;				//10ms脉冲
    // }
  
    // else
    // {
    //     tempchannel1 = tempchannel2 = tempchannel3 = 1;     //1-0-1的脉冲 2us
    //     TR1 = 0;			    	   
    //     ET1 = 0;                  //定时器关闭计时   
    // }
}

void Tim0Isr( void ) interrupt 1   //10ms
{
    if (rev_timeout != 0)  //uart1中设定为50 开始执行
    {
        rev_timeout--;
        if( rev_timeout == 0 )  //超时
        {
            if( rev_bytenum > 0 )  //接收的数据包不为空
            {
                rev_end = 1;   //接收完毕标志位亮起
                rev_bytenum = 0;  //初始化接收缓冲区
            }
        }
    } 
}

void Tim3Isr(void) interrupt 19 
{
    
}


