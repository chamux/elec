#include "music.h"
#include "timer.h"
#include "uart_api.h"

void musical_keyboard()
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

void play_score_init()
{
  init_timer0(0x4,0xff,TEMPO);  //tempo 120
  bip_config(DIV_100,PRESC_100,COUNT_100);
}

void play_score(Note const * score)
{
	short i=1;

	while(score[i].pitch)
	{
		if(score[i].pitch!=SIL)
		{
			bip_change_count(score[i].pitch);
			bip_start();
		}

		wait_change_count(score[0].value*score[i].value);
		wait();

		bip_stop();
		wait_change_count(STACCATO);
		wait();

		i++;
	}
	bip_end();
}

// 2/4
Note const clair_lune[]={{0,LARGO},
			 {FA,CROCHE},{FA,CROCHE},{FA,CROCHE},{SOL,CROCHE},
			 {LA,NOIRE},{SOL,NOIRE},
			 {FA,CROCHE},{LA,CROCHE},{SOL,CROCHE},{SOL,CROCHE},
			 {FA,NOIREP},{SIL,CROCHE}, 
			 {FA,CROCHE},{FA,CROCHE},{FA,CROCHE},{SOL,CROCHE},
			 {LA,NOIRE},{SOL,NOIRE},
			 {FA,CROCHE},{LA,CROCHE},{SOL,CROCHE},{SOL,CROCHE},
			 {FA,NOIREP},{SIL,CROCHE}, 
			 {SOL,CROCHE},{SOL,CROCHE},{SOL,CROCHE},{SOL,CROCHE},
			 {RE,NOIRE},{RE,NOIRE},
			 {SOL,CROCHE},{FA,CROCHE},{MI,CROCHE},{RE,CROCHE},
			 {DO,NOIREP},{SIL,CROCHE},
			 {FA,CROCHE},{FA,CROCHE},{FA,CROCHE},{SOL,CROCHE},
			 {LA,NOIRE},{SOL,NOIRE},
			 {FA,CROCHE},{LA,CROCHE},{SOL,CROCHE},{SOL,CROCHE},
			 {FA,NOIREP},{SIL,CROCHE}, 
			 {END,0}};


//3/8 -> 3/4   -> without staccato
Note const fur_elise[]={{0,ALLEGRO},
			{MI8,CROCHE},{REd8,CROCHE},
			{MI8,CROCHE},{REd8,CROCHE},{MI8,CROCHE},{SI,CROCHE},{RE8,CROCHE},{DO8,CROCHE},
			{LA,NOIRE},{SIL,CROCHE},{DO,CROCHE},{MI,CROCHE},{LA,CROCHE},
			{SI,NOIRE},{SIL,CROCHE},{MI,CROCHE},{SOLd,CROCHE},{SI,CROCHE},
			{DO8,NOIRE},{SIL,CROCHE},{MI,CROCHE},{MI8,CROCHE},{REd8,CROCHE},
			{MI8,CROCHE},{REd8,CROCHE},{MI8,CROCHE},{SI,CROCHE},{RE8,CROCHE},{DO8,CROCHE},
			{LA,NOIRE},{SIL,CROCHE},{DO,CROCHE},{MI,CROCHE},{LA,CROCHE},
			{SI,NOIRE},{SIL,CROCHE},{MI,CROCHE},{DO8,CROCHE},{SI,CROCHE},
			{LA,BLANCHE},

			{MI8,CROCHE},{REd8,CROCHE},
			{MI8,CROCHE},{REd8,CROCHE},{MI8,CROCHE},{SI,CROCHE},{RE8,CROCHE},{DO8,CROCHE},
			{LA,NOIRE},{SIL,CROCHE},{DO,CROCHE},{MI,CROCHE},{LA,CROCHE},
			{SI,NOIRE},{SIL,CROCHE},{MI,CROCHE},{SOLd,CROCHE},{SI,CROCHE},
			{DO8,NOIRE},{SIL,CROCHE},{MI,CROCHE},{MI8,CROCHE},{REd8,CROCHE},
			{MI8,CROCHE},{REd8,CROCHE},{MI8,CROCHE},{SI,CROCHE},{RE8,CROCHE},{DO8,CROCHE},
			{LA,NOIRE},{SIL,CROCHE},{DO,CROCHE},{MI,CROCHE},{LA,CROCHE},
			{SI,NOIRE},{SIL,CROCHE},{MI,CROCHE},{DO8,CROCHE},{SI,CROCHE},
			{LA,NOIRE},{SIL,CROCHE},{SI,CROCHE},{DO8,CROCHE},{RE8,CROCHE},

			{MI8,NOIREP},{SOL,CROCHE},{FA8,CROCHE},{MI8,CROCHE},
			{RE8,NOIREP},{FA,CROCHE},{MI8,CROCHE},{RE8,CROCHE},
			{DO8,NOIREP},{MI,CROCHE},{RE8,CROCHE},{DO8,CROCHE},
			{SI,NOIRE},{SIL,CROCHE},{MI,CROCHE},{MI8,CROCHE},{SIL,CROCHE},
			{SIL,CROCHE},{MI8,CROCHE},{MI16,CROCHE},{SIL,NOIRE},{REd8,CROCHE},
			{MI8,CROCHE},{SIL,NOIRE},{REd8,CROCHE},{MI8,CROCHE},{REd8,CROCHE},
			{MI8,CROCHE},{REd8,CROCHE},{MI8,CROCHE},{SI,CROCHE},{RE8,CROCHE},{DO8,CROCHE},
			{LA,NOIRE},{SIL,CROCHE},{DO,CROCHE},{MI,CROCHE},{LA,CROCHE},
			{SI,NOIRE},{SIL,CROCHE},{MI,CROCHE},{SOLd,CROCHE},{SI,CROCHE},
			{DO8,NOIRE},{SIL,CROCHE},{MI,CROCHE},{MI8,CROCHE},{REd8,CROCHE},
			{MI8,CROCHE},{REd8,CROCHE},{MI8,CROCHE},{SI,CROCHE},{RE8,CROCHE},{DO8,CROCHE},
			{LA,NOIRE},{SIL,CROCHE},{DO,CROCHE},{MI,CROCHE},{LA,CROCHE},
			{SI,NOIRE},{SIL,CROCHE},{MI,CROCHE},{DO8,CROCHE},{SI,CROCHE},
			{LA,NOIRE},{SIL,CROCHE},{SI,CROCHE},{DO8,CROCHE},{RE8,CROCHE},

			{MI8,NOIREP},{SOL,CROCHE},{FA8,CROCHE},{MI8,CROCHE},
			{RE8,NOIREP},{FA,CROCHE},{MI8,CROCHE},{RE8,CROCHE},
			{DO8,NOIREP},{MI,CROCHE},{RE8,CROCHE},{DO8,CROCHE},
			{SI,NOIRE},{SIL,CROCHE},{MI,CROCHE},{MI8,CROCHE},{SIL,CROCHE},
			{SIL,CROCHE},{MI8,CROCHE},{MI16,CROCHE},{SIL,NOIRE},{REd8,CROCHE},
			{MI8,CROCHE},{SIL,NOIRE},{REd8,CROCHE},{MI8,CROCHE},{REd8,CROCHE},
			{MI8,CROCHE},{REd8,CROCHE},{MI8,CROCHE},{SI,CROCHE},{RE8,CROCHE},{DO8,CROCHE},
			{LA,NOIRE},{SIL,CROCHE},{DO,CROCHE},{MI,CROCHE},{LA,CROCHE},
			{SI,NOIRE},{SIL,CROCHE},{MI,CROCHE},{SOLd,CROCHE},{SI,CROCHE},
			{DO8,NOIRE},{SIL,CROCHE},{MI,CROCHE},{MI8,CROCHE},{REd8,CROCHE},
			{MI8,CROCHE},{REd8,CROCHE},{MI8,CROCHE},{SI,CROCHE},{RE8,CROCHE},{DO8,CROCHE},
			{LA,NOIRE},{SIL,CROCHE},{DO,CROCHE},{MI,CROCHE},{LA,CROCHE},
			{SI,NOIRE},{SIL,CROCHE},{MI,CROCHE},{DO8,CROCHE},{SI,CROCHE},
			{LA,NOIRE},{SIL,CROCHE},{SI,CROCHE},{DO8,CROCHE},{RE8,CROCHE},
			{LA,BLANCHE},{SIL,BLANCHE},

			{END,0}};
