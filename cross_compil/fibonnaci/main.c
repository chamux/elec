#include "fibo.h"
#include "uart_api.h"

int main() 
{
  
  serial_init();

  //intToHexa((long)0xABEF1359);
  //serial_putc('\n');
  //intToDeci((long)987654321);
  fibo(10);

  return 0; //EXIT_SUCCESS
}

