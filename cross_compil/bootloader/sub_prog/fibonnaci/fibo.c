#include "uart_api.h"
#include "fibo.h"

char nibbleToAscii(unsigned char byte);

void intToHexa(unsigned long nb)
{
  short i;
  unsigned char byte;
  unsigned short first_non_zero = 0;

  for(i=3 ; i>=0 ; i--)
  {
    byte=nb>>(unsigned short)8*i;
    nb-=byte<<(unsigned short)8*i;

    if(!(first_non_zero == 0 && byte == 0))
    {
      serial_putc(nibbleToAscii(byte>>4));
      serial_putc(nibbleToAscii(byte&0x0F));
      first_non_zero = 1;
    }
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
    serial_puts("\n\r",2);
    aux = u1;
    u1 += u0;
    u0 = aux;
  }
}
