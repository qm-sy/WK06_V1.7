#include "uart.h"
#include "serial_comport.h"
#include "interrupt.h"


void Uart1_Sendbyte( uint8_t dat )
{   
    while(busy_flag1);
    busy_flag1 = 1;
    SBUF = dat;
}

void Uart4_Sendbyte( uint8_t dat )
{
    while(busy_flag4);
    busy_flag4 = 1;
    S4BUF = dat;
}


void Uart1_SendStr( uint8_t *sendstr )
{   
    while(*sendstr)
    {
        Uart1_Sendbyte( *sendstr++ );
    }
}

void Uart4_SendStr( uint8_t *sendstr )
{   
    while(*sendstr)
    {
        Uart4_Sendbyte( *sendstr++ );
    }
}

//void rs485()
//{
//    if(SBUF == 0X85 && busy_flag2 == 1)   
//    {    
//        TxRxSwitch = 1;
//        delay_ms(5);    //延时1ms，不可省去
//        
//        Uart1SendStr("madezhenfan \r\n");
//        delay_ms(5);   //延时根据内容调，发送内容越多，延时越久
//        
//        TxRxSwitch = 0;
//        delay_ms(5);    //延时1ms，不可省去
//            
//        busy_flag2 = 0;
//    }
//}

// char putchar( char c )  // 串口重定向需要添加头文件stdio.h
// {
//     S4BUF = c;
//     while(busy_flag4);
//     busy_flag4 = 1;
//     return c;
// }

char putchar(char c)  // 串口重定向需要添加头文件stdio.h
{
    SBUF = c;
    while(!TI);
    TI = 0;
    return c;
}