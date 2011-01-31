#include "music.h"
#include "timer.h"
#include "uart_api.h"

void music()
{
	short test=1;

	bip_config(DIV_100,PRESC_100,200);
	serial_puts("\n\r\n\r---Music---\n\r");

	while(test)
	{
		switch(serial_getc())
		{
		case 's':
		case 'S'://Music Start
			bip_start();
			break;
		case 'a'://do
		case 'A':
			bip_change_count(DO);
			break;
		case 'z'://re
		case 'Z':	
			bip_change_count(RE);
			break;
		case 'e'://mi
		case 'E':
			bip_change_count(MI);
			break;
		case 'r'://fa
		case 'R':
			bip_change_count(FA);
			break;
		case 't'://sol
		case 'T':
			bip_change_count(SOL);
			break;
		case 'y'://la
		case 'Y':
			bip_change_count(LA);
			break;
		case 'u'://si
		case 'U':
			bip_change_count(SI);
			break;
		case 'i'://Do
		case 'I':
			bip_change_count(DO8);
			break;
		case 'q'://Quit
		case 'Q':
			test=0;
			bip_end(); // to prevent noise
			break;
		default://Silence
			bip_stop();
			break;
		}
	}
}

void play_score(unsigned long const * score, unsigned long noire)
{
	short i=0;

	bip_config(DIV_100,PRESC_100,200);
	bip_start();

	while(score[i])
	{
		bip_change_count(score[i]);
		wait_change_count(noirescore[i+1]);
		wait();
		i+=2;
	}
	bip_end();
}
