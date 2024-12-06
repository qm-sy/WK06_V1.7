#ifndef __SERIAL_COMPORT_H_
#define __SERIAL_COMPORT_H_

#include "sys.h"

void Uart1_Sendbyte( uint8_t dat );
void Uart1_SendStr( uint8_t *sendstr );
void Uart4_Sendbyte( uint8_t dat );
void Uart4_SendStr( uint8_t *sendstr );

#endif