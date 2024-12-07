#ifndef __EEPROM_READ_WRITE_H_
#define __EEPROM_READ_WRITE_H_

#include "eeprom.h"
#include "temp_monitor.h"

extern bit eeprom_write_flag;

void eeprom_read_write( void );
void eeprom_data_init( void );

#endif 