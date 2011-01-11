#include "timer.h"

void init_timer3(	unsigned long rTCFG1,		//rTCFG1 : divider value
	 					unsigned long rTCFG0,		//rTCFG0 : prescaler value
						unsigned long rTCNTB3,		//rTCNTB3 : value of timer
						unsigned long inverter)
{
  TCFG1 &= 0xfff0fff;
  TCFG1 |= rTCFG1;

  TCFG0 &= 0xfff00ff;
  TCFG0 |= rTCFG0;

  TCON &= 0xff0ffff;		//reset of TCON (only timer 3)
  TCNTB3 = rTCNTB3;		//loading timer 3
  TCON |= 0x0020000;		//manuel update ON
  TCON &= 0xff0ffff;		//manuel update OFF
  TCON |= inverter; 

}



void wait1ms(unsigned long inverter)
{
  init_timer3(	0x0002000, 			//divide MCLK by 8
					0, 					//prescaler = 0
					count_begin_1,
					inverter);
  TCON |= 0x10000;		    		//start
  while(TCNTO3 != 0);

}



void wait100ms(unsigned long inverter)
{
 init_timer3(	0x0003000,				//divide MCLK by 16 
					0x0001300, 				//prescaler = 19
					count_begin_100,
					inverter);
  TCON |= 0x0010000;		            //start
  while(TCNTO3 != 0);

}


void wait(unsigned long time_ms)
{
  unsigned long i;
  for(i = 0; i < time_ms ; i++)
    wait1ms(0);
}


void waitInverter(unsigned long time_ms)
{
  unsigned long i;
  for(i = 0; i < time_ms ; i++)
    wait1ms(0x0004000);
}


void bip()
{
  PCONE &= 0x3cfff;		//PE6[13:12] <= 0
  PCONE |= 0x02000;		//put TOUT3 on PE6

  while(1)
  {
    waitInverter(1);
  }


}
