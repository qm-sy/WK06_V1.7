#ifndef _SCREEN_H_
#define _SCREEN_H_

#define MASTER_ADDR         0x51        //单片机slave id
#define SLAVE_ADDR_SCREEN   0X63        //屏幕slave id

#include "serial_comport.h"
#include "temp_monitor.h"
#include "eeprom_read_write.h"
#include "interrupt.h"
#include "wind_crl.h"

void screen_init();
void screen_send_over();
void receive_form_screen( void );
void sendstr_to_screen(const char* prefix,uint8_t value);

#endif