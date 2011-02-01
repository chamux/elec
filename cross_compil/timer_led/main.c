#include "led.h"
#include "uart_api.h"
#include "music.h"



int main() 
{
	play_score_init();
	
	play_score(fur_elise);

	serial_init();
	switchAllOnState(ON);
	musical_keyboard();

	chenillard();

	return 0; //EXIT_SUCCESS
}

