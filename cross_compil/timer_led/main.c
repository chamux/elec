#include "led.h"
#include "timer.h"
#include "uart_api.h"

void music();

int main() 
{
	serial_init();
	switchAllOnState(ON);
	music();
	chenillard();

	return 0; //EXIT_SUCCESS
}

#define	RAPPORT 206250 //66000000/DIV_VAL/(PRESC+1)

void music()
/* TODO Use a formula to compute count :
   the freq of the note is 2^(n/12)*440
 */
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
			bip_change_count(RAPPORT/262);
			break;
		case 'z'://re
		case 'Z':	
			bip_change_count(RAPPORT/294);
			break;
		case 'e'://mi
		case 'E':
			bip_change_count(RAPPORT/330);
			break;
		case 'r'://fa
		case 'R':
			bip_change_count(RAPPORT/350);
			break;
		case 't'://sol
		case 'T':
			bip_change_count(RAPPORT/392);
			break;
		case 'y'://la
		case 'Y':
			bip_change_count(RAPPORT/440);
			break;
		case 'u'://si
		case 'U':
			bip_change_count(RAPPORT/494);
			break;
		case 'i'://Do
		case 'I':
			bip_change_count(RAPPORT/523);
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
