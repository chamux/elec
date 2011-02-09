#include "uart_api.h"
#include "timer.h"

#define UTRSTAT0 (*(volatile unsigned long *)0x01D00010)
#define UTXH0    (*(volatile unsigned long *)0x01D00020)   //when the endian mode is Little Endian
#define URXH0    (*(volatile unsigned long *)0x01D00024)   //when the endian mode is Little Endian
#define ULCON0   (*(volatile unsigned long *)0x01D00000)
#define UCON0    (*(volatile unsigned long *)0x01D00004)
#define UBRDIV0  (*(volatile unsigned long *)0x01D00028)
#define UFCON0   (*(volatile unsigned long *)0x01D0008)

#define bps      115200
#define MCLK     66000000


void serial_init(){

	//Setting up of ULCON0 : normal mode, no parity, one stop bit, word length = 8bits 
	ULCON0 = 0x03;
	//Setting up of UCON0 : polling mode
	UCON0 = 0x005;
	//Setting up UBRDIV0 : 
	UBRDIV0 = (int)(MCLK/(bps*16)) - 1;
	//FIFO enabled
	UFCON0 = 0xf1;
}

void serial_putc(char c)
{
	while(!(UTRSTAT0 & 0x02));
	UTXH0 = c;
}

char serial_getc()
{
	while(!(UTRSTAT0 & 0x01));
	return URXH0; 
}

void serial_puts(char * s)
{ 
	while(*s)
	{
		serial_putc(*s);
		s++;
	}
}

inline void serial_newLine()
{
	serial_puts("\n\r");
}

short serial_getcWithTimer(char * charac)
{
	short test;
	TCON |= 0x0000002;		//manuel update ON
	TCON &= 0xffffffd;		//manuel update OFF
	TCON |= 0x000001;		//start
  
	while( (!(UTRSTAT0 & 0x01)) && TCNTO0);

	TCON &= ~0x000001;

	test=UTRSTAT0 & 0x01;
	*charac=test?URXH0:-1; 
	return test;
}
