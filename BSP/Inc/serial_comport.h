#ifndef __SERIAL_COMPORT_H_
#define __SERIAL_COMPORT_H_

#include "sys.h"

void Uart1Sendbyte( uint8_t dat );
void Uart1SendStr( uint8_t *sendstr );

#endif