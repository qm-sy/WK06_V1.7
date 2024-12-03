#include "key.h"

#define   ChannelChoose     2
#define   ModeChoose        4
#define   FunctionKey       3
#define   PowerKey          0
#define   UpKey             1
#define   DownKey           5
#define   FanUp             9
#define   FanDown           13

void key_scan()
{
    if ( scan_start_bit == 1 )
    {
        switch(key_val)
        {
            case UpKey:
                key2_up();
                delay_ms(50);
                break;
            
            case ChannelChoose:
                key3_channel_temp_choose();
                delay_ms(50);
                break;
            
            case ModeChoose:                    //复用同步切换、mode切换
                key5_mode_sync_choose();
                delay_ms(50);
                break;
                
            case DownKey:
                key6_down();
                delay_ms(50);
                break;
            
            case FanUp:
                key42_fan_up();   
                delay_ms(50); 
                break;
            
            case FanDown:
                key46_fan_down();          
                delay_ms(50);
                break;
        }
    }
}

void key42_fan_up()
{
    /*1.蜂鸣器响                             */
    buzzer = buzzer_bit = 0;

    /*2.风扇档位+1 并刷新显示                 */
    wind_num += 1;
    if ( wind_num > 6 )
    {
        wind_num = 6;
    }
    wind_crl(wind_num);
    wind_dis(wind_num);

    /*3.将新的风扇档位记录至eeprom            */
    eeprom_data_write();
}

void key46_fan_down()
{
    /*1.蜂鸣器响                             */
    buzzer = buzzer_bit = 0;

    /*2.风扇档位+1 并刷新显示                 */
    wind_num -= 1;
    if ( wind_num < 0)
    {
        wind_num = 0;
    }
    wind_crl(wind_num);
    wind_dis(wind_num);

    /*3.将新的风扇档位记录至eeprom            */
    eeprom_data_write();
}

void key2_up()
{
    /*1.蜂鸣器响                             */
    buzzer = buzzer_bit = 0;

    /*2.加热功率+5 并刷新显示                 */
    power_num += 5;
    if ( power_num > 100 )
    {
        power_num = 100;
    }
    power_crl(power_num);
    num_dis(power_num);

    /*3.将新的功率大小记录至eeprom            */
    eeprom_data_write();
}

void key6_down()
{

    /*1.蜂鸣器响                             */
    buzzer = buzzer_bit = 0;

    /*2.加热功率-5 并刷新显示                 */
    power_num -= 5;
    if ( power_num < 0 )
    {
        power_num = 0;
    }
    power_crl(power_num);
    num_dis(power_num);

    /*3.将新的功率大小记录至eeprom            */
    eeprom_data_write();
}

void key3_channel_temp_choose()
{
    uint8_t channelchoose_longpress_cnt = 100;
    while((key_val==ChannelChoose)&&(channelchoose_longpress_cnt>0))
    {
        channelchoose_longpress_cnt--; 
        delay_ms(10);
    }
    if ( channelchoose_longpress_cnt == 0 )           //长按1s，开启同步 
    {
        temp_set();
    }

    if ( key3_longpress_flag == 0 )                  //防误触   
    {   
        channel_choose();                        //短按，mode切换
    }
}

void temp_set()
{
    /*1.蜂鸣器响,去除 %符号，使能 ℃符号                     */
    buzzer = buzzer_bit = 0;
    percentage_dis(DIS_ON);
    celsius_dis(DIS_OFF);

    /*2.防误触，以防退出                                    */
    delay_ms(500);

    /*3.再次点击ChannelChoose退出预加热温度设置              */
    while(key_val != ChannelChoose)
    {
        if ( temp_blink_flag )               //数字闪烁
        {
            num_dis(temp_num);  
        } else {
            lcd_write_val(addr_tab[ADDR_0B],0x00);
            lcd_write_val(addr_tab[ADDR_0A],0X00);
            lcd_write_val(addr_tab[ADDR_07],0X00);
            lcd_write_val(addr_tab[ADDR_06],0X00);
        }

        if ( key_val == UpKey )              //温度加
        {
            buzzer = buzzer_bit = 0;
            temp_num += 5;
            if ( temp_num > 200 )
            {
                temp_num = 200;
            }
            delay_ms(100);                  //防止连点
        }

        if ( key_val == DownKey )            //温度减
        {
            buzzer = buzzer_bit = 0;
            temp_num -= 5;
            if ( temp_num < 50 )
            {
                temp_num = 50;
            }
            delay_ms(100);                  //防止连点
        }
    }

    buzzer = buzzer_bit = 0;                //退出声
    key3_longpress_flag = 1;                // key3 防误触标志位亮起   
    num_dis(power_num);                     //防止处于闪烁数字消失阶段，确保数字显示

    /*4.去除 ℃符号，使能 %符号                            */
    celsius_dis(DIS_OFF);
    percentage_dis(DIS_ON);

    /*5.记录预加热温度值至eeprom                            */
    eeprom_data_write();
}

void channel_choose()
{
    /*1.蜂鸣器响                                          */
    buzzer = buzzer_bit = 0;

    /*2.加热通道切换 并刷新显示                            */
    channel_num += 1;
    if ( channel_num == 7 )
    {
        channel_num = 1;
    }
    channel_dis(channel_num);
    
    /*3.将新的功率大小记录至eeprom                          */
    eeprom_data_write();
}
 
void key5_mode_sync_choose()
{
    uint8_t modechoose_longpress_cnt = 100;
    while((key_val==ModeChoose)&&(modechoose_longpress_cnt>0))  //长按1s判断，开启同步
    {
        modechoose_longpress_cnt--; 
        delay_ms(10);
    }
    
    if ( modechoose_longpress_cnt == 0 )            
    {
        sync_choose();
    }

    if ( key5_longpress_flag == 0 )                //短按，mode切换
    {
        mode_choose();
    }
}

void sync_choose()
{
    /*1.蜂鸣器响                                           */
    buzzer = buzzer_bit = 0;

    key5_longpress_flag = 1;         // key5 防误触标志位亮起 

    /*2.切换同步状态 :开or关  并刷新显示                     */
    sync_bit = ~sync_bit;            
    sync_dis(sync_bit);

    /*3.判断同步状态并进行处理                               */
    sync_judge();

    /*4.记录同步状态至eeprom                                */
    eeprom_data_write();        
}           


void mode_choose()
{
    /*1.蜂鸣器响                                           */
    buzzer = buzzer_bit = 0;

    /*2.模式切换 1~5  清屏，然后显示mode序号和 mode字符      */
    mode_num += 1;
    if ( mode_num == 6)
    {
        mode_num = 1;
    }
    lcd_clear();   
    num_dis(mode_num);              
    mode_dis(DIS_ON);       
    delay_ms(500);        

    /*3.读取eeprom内记录参数并导入                          */ 
    eeprom_data_read(mode_num);  //

    /*4.判断同步状态并进行处理                              */
    sync_judge();       

    /*5.二次清屏，然后刷新界面                              */
    lcd_clear();
    sun_dis(~sync_bit);
    sync_dis(sync_bit);
    num_dis(power_num);
    channel_dis(channel_num);
    percentage_dis(DIS_ON);
    wind_dis(wind_num);

    /*6.记录同步序号至eeprom                              */
    eeprom_mode_save();         
}

