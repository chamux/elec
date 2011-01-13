#include "uart_api.h"
//#include "timer.h"
//#include "led.h"
//#include "convert.h"
//#include "boot.h"

int main()
{
 // char receive_char;

  serial_putc(serial_getc());


 /* while(0)
  {
	 serial_puts("BOOTLOADER IS SPEAKING !!\n\r",27);
	 receive_char = serial_getc();
	 unsigned long addr;

	 switch(receive_char)
	 {
		case 'L' :
		  switchOnOff(4,OFF);
		  switchOnOff(1, ON);
		  //address : 0x????????
		  addr = getAddress();
		  if(testAddress(addr))
			 storeBytes(addr);
		  else
			 switchOnOff(4,ON);
		  switchOnOff(1,OFF);

		  break;

		case 'G' :
		  break;

		case 'R' :
		  break;

	 }



  }*/
  return 0;
}


/*unsigned long getAddress()
{
  unsigned short i;
  char receive[10];

  for(i=0; i<10; i++)
  {
	 receive[i] = serial_getc();
  }
  //TODO address without starting zero
  return ((receive[0] == '0') & (receive[1] == 'x')) ? asciiToHex(receive + 2) : 0;

}




inline unsigned short testAddress(unsigned long addr)
{
  return ((addr > (unsigned long)& _bss_end_) & (addr < STACK_END));

}


void storeBytes(unsigned long addr)
{
  intToHexa(addr);

}*/
