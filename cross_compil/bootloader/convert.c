#include "uart_api.h"
#include "convert.h"

inline char nibbleToAscii(unsigned char byte);
inline unsigned long asciiToNibble(char charac);

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

unsigned long asciiToHex(char * receive)
{

  unsigned short i;
  unsigned long hex = 0;
  for(i=0; i< 8; i++)
  {
	 hex = hex*16 + asciiToNibble(receive[i]);
  }
  return hex;

}

inline unsigned long asciiToNibble(char charac)
{
  return (charac > 57) ? charac - 87 : charac - 48;
}

