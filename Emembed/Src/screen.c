#include "screen.h"

uint8_t screen_hand_flag = 0;

void receive_form_screen( void )
{
    if( RX1_rev_end_flag == 1 )
    {
        RX1_rev_end_flag = 0;
        if(RX1_buf[0] == MASTER_ADDR)        //屏幕→主机
        {
            switch(RX1_buf[1])
            { 
                case SLAVE_ADDR_SCREEN:     //屏幕connect 0x63
                    screen_init();
                    break;
                    
                case 0xA1:                  //写入温度设定值
                    setting_temp1 = RX1_buf[2];
                    setting_temp2 = RX1_buf[3];
                    setting_temp3 = RX1_buf[4];
                    setting_temp4 = RX1_buf[5];

                    eeprom_write_flag = 1; 
                    
                    break;
                
                case 0xA2:                

                    break;

                case 0xA3:                  

                    break;
                
                case 0xA4:                

                    break;

                case 0xA5:                  

                    break;
                
                case 0xA6:                  

                    break;
            }
        }
    }


}

void screen_init()
{
    if(RX1_buf[2]==0xCA)
    {    
        Uart1_SendStr("t0.txt=\"Connecting...\"");     screen_send_over(); 
    }

    if(RX1_buf[2]==0xCB)
    {
        Uart1_SendStr("t0.txt=\"Connected\"");          screen_send_over(); 
        //sendstr_to_screen("n0.val=%d",wind_level);
        sendstr_to_screen("n0.val=%d",setting_temp1); 
        sendstr_to_screen("n1.val=%d",setting_temp2); 
        sendstr_to_screen("n2.val=%d",setting_temp3); 
        sendstr_to_screen("n3.val=%d",setting_temp4); 
              
        screen_hand_flag = 1;
    }
     
    if(screen_hand_flag == 1)
    {
        if(RX1_buf[2]==0xCC)
        {
            screen_hand_flag = 2;
        }
        else
        {
            Uart1_SendStr("getFrameFlag1=1");           screen_send_over();  
            Uart1_SendStr("tm0.en=1");                  screen_send_over(); 
        }
    }  
}

void sendstr_to_screen(const char* prefix, uint8_t value)
{
    char send_buf[50];
    
    sprintf(send_buf, "%s%d", prefix, (int)value);

    Uart1_SendStr(send_buf);

    screen_send_over();
    
    delay_ms(120);
}

void screen_send_over()
{
    Uart1_Sendbyte(0xff);
    Uart1_Sendbyte(0xff);
    Uart1_Sendbyte(0xff);

    delay_ms(120);
}