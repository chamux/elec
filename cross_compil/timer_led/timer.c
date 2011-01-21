#include "timer.h"

void init_timer3(unsigned long div,
		 unsigned long presc,
		 unsigned long count)
{
  TCFG1 &= 0xfff0fff;
  TCFG1 |= div;

  TCFG0 &= 0xfff00ff;
  TCFG0 |= presc;

  TCON &= 0xff0ffff;		//reset of TCON (only timer 3)

  TCMPB3 = count/2;
  TCNTB3 = count;		//loading timer 3
}

void wait()
{
  TCON |= 0x0020000;		//manuel update ON
  TCON &= 0xffdffff;		//manuel update OFF
  TCON |= 0x10000;		//start
  while(TCNTO3);
  TCON &= ~0x10000;		//stop
}

void bip_config(unsigned long div,    
	 unsigned long presc,
         unsigned long count)
{
  PCONE &= 0x3cfff;		//PE6[13:12] <= 0
  PCONE |= 0x02000;		//put TOUT3 on PE6

 
  TCFG1 &= 0xfff0fff;
  TCFG1 |= div;

  TCFG0 &= 0xfff00ff;
  TCFG0 |= presc;

  TCON &= 0xff0ffff;		//reset of TCON (only timer 3)
  TCON |= 0x0080000;            //autoreload

  TCMPB3 = count/2;
  TCNTB3 = count;		//loading timer 3

  TCON |= 0x0020000;		//manuel update ON
  TCON |= INVERTER;
  
  TCON &= 0xffdffff;		//manuel update OFF
  TCON &= 0xffbffff;		//inverter bit OFF


}
void bip_stop()
{
  TCON &= ~0x10000;
}

void bip_start()
{
  TCON |= 0x10000;
}

void bip_end()
{
  PCONE &= 0x3cfff;		//PE6[13:12] <= 0
}

void bip_change_count(unsigned long count)
{
  TCMPB3 = count/2;
  TCNTB3 = count;
}
