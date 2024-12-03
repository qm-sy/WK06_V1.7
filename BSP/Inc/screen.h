#ifndef __SCREEN_H_
#define __SCREEN_H_

#include "gpio.h"


#define DIS_ON  1
#define DIS_OFF 0

void lcd_init();
void lcd_clear();
void lcd_display();
void lcd_write_val(uint8_t addr,uint8_t dat);
void TM1722_Write_Byte(unsigned char dat);

void wind_dis(uint8_t num);
void num_dis(uint8_t num);
void channel_dis(uint8_t num);
void sun_dis(bit on_off);
void sync_dis(bit on_off);
void alarm_dis(bit on_off);
void F_dis(bit on_off);
void M_dis(bit on_off);
void R_dis(bit on_off);
void Celsius_dis(bit on_off);
void mode_dis(bit on_off);
void percentage_dis(bit on_off);
void cur_dis(bit on_off);
void set_dis(bit on_off);
void fan_center_dis(bit on_off);
void fan_leaf1_dis(bit on_off);
void fan_leaf2_dis(bit on_off);

#endif 