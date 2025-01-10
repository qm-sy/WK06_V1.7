/*
P0.0:RX3        P1.0		    P2.0:PWM5       P3.0:RX1         P4.0		    P5.0:E_DC_24out3 P6.0		    P7.0
P0.1:TX3        P1.1		    P2.1:PWM6       P3.1:TX1         P4.1:220v_1    P5.1		     P6.1		    P7.1
P0.2:RX4        P1.2		    P2.2:PWM7       P3.2:INT0        P4.2:220v_2    P5.2		     P6.2		    P7.2
P0.3:TX4        P1.3		    P2.3:PWM8       P3.3		     P4.3:220v_3    P5.3             P6.3		    P7.3
P0.4:NTC1       P1.4:YW_1       P2.4		    P3.4		     P4.4:220v_4    P5.4		     P6.4		    P7.4:DC_24in
P0.5:NTC2       P1.5:YW_2       P2.5		    P3.5:E_DC_24out2 P4.5		    P5.5		     P6.5		    P7.5:buzzer
P0.6:NTC3       P1.6		    P2.6:relay      P3.6		     P4.6		    P5.6		     P6.6		    P7.6:DR3
P0.7:           P1.7		    P2.7:DC_24out2  P3.7		     P4.7		    P5.7		     P6.7		    P7.7:
                                                                                                                         */

#include "gpio.h"

void GPIO_Init( void )
{
    P0M0 = 0x8a;    P0M1 = 0x70;        // P0.1 0.3为推挽 P0.4~P0.7为高阻输入
    P1M0 = 0x00;    P1M1 = 0X00;        //
    P2M0 = 0xcf;    P2M1 = 0x00;        //P2.0~2.3  2.6、2.7为推挽      
    P3M0 = 0x22;    P3M1 = 0X00;        //P3.1、3.5为推挽
    P4M0 = 0x1e;    P4M1 = 0x00;        //P4.1 4.2 4.3 4.4为推挽      
    P5M0 = 0x01;    P5M1 = 0X00;        //P5.4为推挽
    P6M0 = 0x10;    P6M1 = 0X00;        //
    P7M0 = 0x60;    P7M1 = 0X00;        //P7.5、7.6为推挽

    P1PU  = 0x30;                       //P1.4、P1.5启用上拉电阻
    P7PU |= 0x10;                       //P7.4启用上拉电阻
}
  