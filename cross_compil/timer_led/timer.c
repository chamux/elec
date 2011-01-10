#include "timer.h"

void wait100ms()
{
  TCFG1 = TCFG1 | 0x3000;						//divide by 16 MCLK
  TCON = TCON | 0x20000;						//manual update on
  TCNTB3 = count_begin_100;					//load timer 3 with count_begin
  TCON = (TCON & 0xdffff) | 0x10000;		//manual update off and start
  while(TCNTO3 != 0);

}


void wait(unsigned long time)
{
  unsigned long i;
  for(i = time; i >= 0; i--)
	 wait100ms();
}

void wait1ms()
{
  TCFG1 = (TCFG1 | 0x2000) & 0xefff;		//divide by 8 MCLK
  TCON = TCON | 0x20000;						//manual update on
  TCNTB3 = count_begin_1;						//load timer 3 with count_begin
  TCON = (TCON & 0xdffff) | 0x10000;		//manual update off and start
  while(TCNTO3 != 0);

}

void wait1s() 
{
  int i;
  for(i = 0; i < 100; i++)
	 wait(100ms);
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
