#include "fibo.h"
#include "uart_api.h"

int main() 
{
  
  serial_init();

  
  //intToHexa((long)0xABEF1359);
  //intToHexa((long)0x000A0B10);
  fibo(10);

  return 0; //EXIT_SUCCESS
}

