#include "uart_api.h"
#include "fibo.h"

char nibbleToAscii(unsigned char byte);

void intToHexa(unsigned long nb)
{
	short i;
	unsigned char byte;

	for(i=3 ; i>=0 ; i--)
	{
		byte=nb>>(unsigned short)8*i;
		nb-=byte<<(unsigned short)8*i;
	
		serial_putc(nibbleToAscii(byte>>4));
		serial_putc(nibbleToAscii(byte&0x0F));
	}
}

char nibbleToAscii(unsigned char byte)
{
	char digit;
	digit=byte+48;

	if(digit>57)
		digit+=7;
	
	return digit;
}

void intToDeci(unsigned long nb)
{
	short i,lastZero=0;
	char out[10];

	for(i=9; i>=0 ; i--)
	{
		out[i]=(nb%10);
		nb/=10;

		if(out[i]==0 && lastZero<i)
			lastZero=i;
		if(out[i]!=0 && lastZero>i)
			lastZero=0;

		out[i]+=48;
	}
	lastZero+=lastZero!=9;

	serial_puts(out+lastZero,10-lastZero);
}

void fibo(short n)
{
	long u0=0, u1=1, aux;
	short i;
	for(i = 0; i < n; i++)
	{
		intToDeci(u0);
		serial_putc('\n');
		aux = u1;
	     	u1 += u0;
		u0 = aux;
	}
}
