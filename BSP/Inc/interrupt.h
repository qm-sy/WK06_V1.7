#ifndef __INTERRUPT_H_
#define __INTERRUPT_H_

#include "gpio.h"
#include "timer.h"

extern bit busy_flag1;          //串口1等待接收标志位
extern bit busy_flag4;          //串口4等待接收标志位

extern bit heating_flag1;
extern bit heating_flag2;
extern bit heating_flag3;
extern bit heating_flag4;

extern bit RX1_rev_end_flag; 
extern uint8_t  RX1_buf[128];
//extern uint16_t phase_shift_time;
//extern uint8_t key_val;
void Uart4_Init();
void sendbyte(uint8_t dat);
void sendstring(uint8_t *sendstr);
void rs485();

#endif 