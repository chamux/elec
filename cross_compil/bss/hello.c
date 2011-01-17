#include "uart_api.h"

int test;
long bouh;
int grr;

int main() 
{
  serial_init();
  serial_putc(test+48);
  serial_putc(bouh+48);
  serial_putc(grr+48);
  while(1)
    serial_putc(serial_getc());

  return 0; //EXIT_SUCCESS
}
