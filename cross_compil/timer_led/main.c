#include "led.h"
#include "timer.h"
#include "uart_api.h"
#include "music.h"

unsigned long const clair_lune[]=
  {FA,6,FA,6,FA,6,SOL,6,LA,12,SOL,12,FA,6,LA,6,SOL,6,SOL,6,FA,24,
   FA,6,FA,6,FA,6,SOL,6,LA,12,SOL,12,FA,6,LA,6,SOL,6,SOL,6,FA,24,
   SOL,6,SOL,6,SOL,6,SOL,6,RE,12,RE,12,
   SOL,6,FA,6,MI,6,RE,6,DO,24,
   FA,6,FA,6,FA,6,SOL,6,LA,12,SOL,12,FA,6,LA,6,SOL,6,SOL,6,FA,24,END,END};


int main() 
{

  init_timer0(0x4,0xff,COUNT_1000/2);
  play_score(clair_lune, COUNT_1000/2);


  /* 	serial_init(); */
  /* 	switchAllOnState(ON); */
  /* 	music(); */
  /* 	chenillard(); */

	return 0; //EXIT_SUCCESS
}

