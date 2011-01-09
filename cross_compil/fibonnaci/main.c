#include "fibo.h"
#include "uart_api.h"

int main() __attribute__((naked));

int main() {
  
  serial_init();

  intToHexa((long)0xABEF1359);

  return 0; //EXIT_SUCCESS
}

