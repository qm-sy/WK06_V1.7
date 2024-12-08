 #include "interrupt.h"

static bit zero_flag = 0;       //外部中断（过零检测）et0响应flag 响应赋值为1

bit busy_flag1    = 0;          //串口1等待接收标志位
bit busy_flag4    = 0;          //串口4等待接收标志位

bit heating_flag1 = 1;
bit heating_flag2 = 1;
bit heating_flag3 = 1;
bit heating_flag4 = 1;

uint8_t TX1_buf[128];
uint8_t TX1_send_bytelength; 
uint8_t TX1_send_cnt;  

bit RX1_rev_end_flag = 0;             //数据包发送完毕标志
uint8_t  RX1_buf[128];    //SBUF RI缓冲区
uint16_t RX1_rev_timeout;    //接收超时
uint8_t  RX1_rev_bytenum = 0;     //接收计数

uint16_t phase_shift_time = 65520;

void Uart1_ISR() interrupt 4 
{   
    if( TI == 1 )
    {
        TI = 0;
        busy_flag1 = 0;
        if(TX1_send_bytelength != 0)
        {
            SBUF = TX1_buf[TX1_send_cnt++];
            TX1_send_bytelength--;
        }
    }
    
    if( RI == 1 )
    {
        RI = 0;
        if(!RX1_rev_end_flag)
        {
            if(RX1_rev_bytenum > 128)
            {
                RX1_rev_bytenum = 0;
            }
            RX1_buf[RX1_rev_bytenum] = SBUF;
            RX1_rev_bytenum++;
        }
        RX1_rev_timeout = 150;
    }
}

void Tim0_ISR( void ) interrupt 1   //1ms
{
    if (RX1_rev_timeout != 0)  //uart1中设定为50 开始执行
    {
        RX1_rev_timeout--;
        if( RX1_rev_timeout == 0 )  //超时
        {
            if( RX1_rev_bytenum > 0 )  //接收的数据包不为空
            {
                RX1_rev_end_flag = 1;   //接收完毕标志位亮起
                RX1_rev_bytenum = 0;  //初始化接收缓冲区
            }
        }
    } 
}

void Uart4_ISR() interrupt 18 using 1
{   
    if(S4CON & S4RI)  
    {
        S4CON &= ~S4RI;
    }
    
    if(S4CON & S4TI)            
    {  
        S4CON &= ~S4TI;  
        busy_flag4 = 0;
    }
}

void ET0_ISR(void) interrupt 0 
{
    heating_channel1 = heating_channel2 = heating_channel3 = heating_channel4 = 1;    
    /*      延时移相        */
    TL1 = phase_shift_time;			    	//设置定时初始值
	TH1 = phase_shift_time>>8;				//设置定时初始值

    zero_flag = 1;
    
    TR1 = 1;			    	//定时器1开始计时      
    ET1 = 1; 
}

void Tim1_ISR(void) interrupt 3 
{

    if( zero_flag == 1 )
    {
        heating_channel1 = ~heating_flag1;
        heating_channel2 = ~heating_flag2;
        heating_channel3 = ~heating_flag3;
        heating_channel4 = ~heating_flag4;
        /*      发送一个10us的脉冲      */
        zero_flag = 0;

        TL1 = 0xF7;				//设置定时初始值
        TH1 = 0xFF;				//设置定时初始值
    }
    else
    {
        heating_channel1 = heating_channel2 = heating_channel3 = heating_channel4 = 1;     //1-0-1的脉冲 2us
        TR1 = 0;			    	   
        ET1 = 0;                  //定时器关闭计时   
    }
}



void Tim3_ISR(void) interrupt 19 
{
    
}



// void Uart4_ISP() interrupt 18 using 1
// {   
//     if(S4CON & S4RI)   
//     {
//         S4CON &= ~S4RI;
//         flag = 1;
//     }
    
//     if(S4CON & S4TI)            
//     {  
//         S4CON &= ~S4TI;  
//         busy = 0;
//     }
// }

// void sendbyte(uint8_t dat)
// {
//         while(busy);
//         busy = 1;
//         S4BUF = dat;
// }

// void sendstring(uint8_t *sendstr)
// {
//     while(*sendstr)
//     {
//         sendbyte(*sendstr++);
//     }
// }

// void rs485()
// {
//     if(S4BUF == 0X85 && flag == 1)   
//     {    
//         DR4 = 1;
//         delay_ms(5);    //延时1ms，不可省去
        
//         sendstring("madezhenfan \r\n");
//         delay_ms(5);   //延时根据内容调，发送内容越多，延时越久
        
//         DR4 = 0;
//         delay_ms(5);    //延时1ms，不可省去
            
//         flag = 0;
//     }
// }