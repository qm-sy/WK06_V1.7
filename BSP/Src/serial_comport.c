#include "uart.h"
#include "serial_comport.h"

bit busy_flag = 0;          //等待接收标志位

void Uart1Sendbyte( uint8_t dat )
{
    while(busy_bit);
    busy_flag = 1;
    SBUF = dat;
}

void Uart1SendStr( uint8_t *sendstr )
{   
    while(*sendstr)
    {
        Uart1Sendbyte( *sendstr++ );
    }
}

char putchar( char c )  // 串口重定向需要添加头文件stdio.h
{
    SBUF = c;
    while(!TI);
    TI = 0;
    return c;
}