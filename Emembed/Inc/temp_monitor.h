#ifndef _TEMP_MONITOR_H_
#define _TEMP_MONITOR_H_

#include "ntc.h"
#include "screen.h"
#include "interrupt.h"

extern uint8_t setting_temp1;
extern uint8_t setting_temp2;
extern uint8_t setting_temp3;
extern uint8_t setting_temp4;
void temp_sacn();


#endif