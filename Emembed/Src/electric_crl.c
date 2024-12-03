
//uint8_t power_on()
//{
//    if(scan_start_bit == 1)
//    {
//        if(key_val == PowerKey)
//        {
//            return 0;
//        }
//    }
//    return 1;
//}

//void power_off()
//{
//    uint8_t continue_cnt;
//    if(scan_start_bit == 1)
//    {
//        continue_cnt = 100;
//        while((key_val==PowerKey)&&(continue_cnt>0))
//        {
//            continue_cnt--; 
//            delay_ms(10);
//        }
//        if(continue_cnt == 0)           //长按1s判断，开启同步 
//        {
//            lcd_clear();
//            power_bit = 0;
//            sun_dis(DIS_OFF);
//            PWMStop();
//            on_off = 1;
//        }
//    }

//}