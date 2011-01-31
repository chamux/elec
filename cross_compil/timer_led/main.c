#include "led.h"
#include "timer.h"
#include "uart_api.h"
#include "music.h"



int main() 
{
	init_timer0(0x4,0xff,TEMPO);  //tempo 120
	play_score(clair_lune);

	serial_init();
	switchAllOnState(ON);
	musical_keyboard();

	chenillard();

	return 0; //EXIT_SUCCESS
}

