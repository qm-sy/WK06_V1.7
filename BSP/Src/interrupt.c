#include "interrupt.h"

static bit zero_flag = 0;       //外部中断（过零检测）et0响应flag 响应赋值为1
uint16_t phase_shift_time = 58400;
uint8_t key_val = 0;

void Uart1Isr() interrupt 4 
{   
    if(TI == 1)
    {
        TI = 0;
        busy_bit = 0;
    }
    
    if(RI == 1)
    {
        RI = 0;
    }
}

void ET0ISR(void) interrupt 0 
{
    tempchannel1 = tempchannel2 = tempchannel3 = 1;    
    /*延时移相                  */
    TL1 = TIM1;			    	//设置定时初始值
	TH1 = TIM1>>8;				//设置定时初始值

    zero_flag = 1;
    
    TR1 = 1;			    	//定时器1开始计时      
    ET1 = 1; 
}

void Tim1Isr(void) interrupt 3 
{

    if((zero_flag == 1)&&(power_bit == 1))
    {
        switch(channel_num)
        {
            case 1: {tempchannel1=0; tempchannel2=1; tempchannel3=1;}break;
            case 2: {tempchannel1=1; tempchannel2=0; tempchannel3=1;}break;
            case 3: {tempchannel1=1; tempchannel2=1; tempchannel3=0;}break;
            case 4: {tempchannel1=0; tempchannel2=0; tempchannel3=1;}break;
            case 5: {tempchannel1=1; tempchannel2=0; tempchannel3=0;}break;
            case 6: {tempchannel1=0; tempchannel2=1; tempchannel3=0;}break;
            case 7: {tempchannel1=0; tempchannel2=0; tempchannel3=0;}break;
        }
            /*1.发送一个10us的脉冲                */
            zero_flag = 0; 

            TL1 = 0xF7;				
            TH1 = 0xFF;				//10ms脉冲
    }
  
    else
    {
        tempchannel1 = tempchannel2 = tempchannel3 = 1;     //1-0-1的脉冲 2us
        TR1 = 0;			    	   
        ET1 = 0;                  //定时器关闭计时   
    }
}

void Tim0Isr( void ) interrupt 1   //10ms
{
    static uint8_t buzzer_continue_cnt = 0;
    static uint8_t fan_rotate_cnt      = 0;
    static uint8_t temp_blink_cnt      = 0;
    static uint8_t key_sacn_cnt        = 0;
    static uint8_t key3_longpress_cnt  = 0;     
    static uint8_t key5_longpress_cnt  = 0;

    /*1.蜂鸣器短暂鸣叫                          */
    if( buzzer_bit == 0 )
    {
        buzzer_continue_cnt++;
        if( buzzer_continue_cnt > 10 )
        {
            buzzer_continue_cnt = 0; 
            buzzer = buzzer_bit = 1;
        }
    } 
    /*2.风扇扇叶交替 旋转效果                    */
    fan_rotate_cnt++;
    if( fan_rotate_cnt > 15 )
    {
        fan_rotate_flag = ~fan_rotate_flag;
        fan_rotate_cnt = 0;
    }

    /*3.设定预加热温度时 数字闪烁效果             */
    temp_blink_cnt++;
    if( temp_blink_cnt > 50 )
    {
        temp_blink_flag = ~temp_blink_flag;
        temp_blink_cnt = 0;
    }

    /*4.监听P07脚状态 0：24V接入 1：24V断开      */
    if ( external24 == 0 )
    {
        external24_flag = 1;  
    }
    else
    {
        external24_flag = 0;
    }

    /*5.100ms扫描一次按键                        */
    if( key_scan_stop_flag == 1 )
    {
        key_sacn_cnt++;
        if( key_sacn_cnt > 10 )
        {
            key_scan_start_flag = 1;
            key_scan_stop_flag  = 0;
            key_sacn_cnt = 0;
        }
    }

    /*6.key3-channelchoose键 长按后防止误触           */
    if( key3_longpress_flag == 1 )
    {
        key3_longpress_cnt++;
        if(key3_longpress_cnt>150)
        {
            key3_longpress_flag = 0;
            key3_longpress_cnt = 0;
        }
    }

    /*7.key5-modechoose键 长按后防止误触           */
    if( key5_longpress_flag == 1 )
    {
        key5_longpress_cnt++;
        if(key5_longpress_cnt>150)
        {
            key5_longpress_flag = 0;
            key5_longpress_cnt = 0;
        }
    }
}

void Tim3Isr(void) interrupt 19 
{
    static uint8_t touch_identify_cnt = 0;

    /*1.50ms 初始化一次按键                        */
    touch_identify_cnt++;
    if(touch_identify_cnt>5)
    {
        touch_identify_cnt=0; 
        key_val = ( P0 & 0X0f );
    }
}


