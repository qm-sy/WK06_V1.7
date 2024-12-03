#ifndef __KEY_H_
#define __KEY_H_

#include "delay.h"
#include "interrupt.h"
#include "eeprom_read_write.h"
#include "screen.h"

void key_scan();
void key42_fan_up();
void key46_fan_down();
void key2_up();
void key6_down();
void key3_channel_temp_choose();
void temp_set();
void channel_choose();
void key5_mode_sync_choose();
void sync_choose();
void mode_choose();

#endif 