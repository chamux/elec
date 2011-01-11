#include "timer.h"

void init_timer3(	unsigned long rTCFG1,		//rTCFG1 : divider value
	 					unsigned long rTCFG0,		//rTCFG0 : prescaler value
						unsigned long rTCNTB3)		//rTCNTB3 : value of timer
{
  TCFG1 &= 0xfff0fff;
  TCFG1 |= rTCFG1;

  TCFG0 &= 0xfff00ff;
  TCFG0 |= rTCFG0;

  TCON &= 0xff0ffff;		//reset of TCON (only timer 3)
  TCNTB3 = rTCNTB3;		//loading timer 3
  TCON |= 0x0020000;		//manuel update ON
  TCON &= 0xff0ffff;		//manuel update OFF

}



void wait1ms()
{
  init_timer3(	0x0002000, 			//divide MCLK by 8
					0, 					//prescaler = 0
					count_begin_1);
  TCON |= 0x10000;		    		//start
  while(TCNTO3 != 0);

}



void wait100ms()
{
 init_timer3(	0x0003000,				//divide MCLK by 16 
					0x0001300, 				//prescaler = 19
					count_begin_100);
  TCON |= 0x0010000;		            //start
  while(TCNTO3 != 0);

}


void wait(unsigned long time_ms)
{
  unsigned long i;
  for(i = 0; i < time_ms ; i++)
    wait1ms();
}


void bip()
{
  TCON = TCON | 0xb0000;						//auto-reload ON and inverter TOUT3
  TCMPB3 = 0;
  PCONE = (PCONE | 0x2000) & 0xefff;		//put TOUT3 on PE6
  while(1)
  {
    wait1ms();
  }


}
