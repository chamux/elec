#include "uart_api.h"
#include "timer.h"
#include "led.h"
#include "convert.h"
#include "boot.h"

int main()
{
	char receive_char;
	unsigned long addr;

	serial_init();
	serial_puts("\n\n\rBOOTLOADER by Bertrand & Samuel\n\r",36); 
	switchAllOnState(OFF);
 
	while(1)
	{
		serial_puts("\tL<addr> : data at addr in\n\r",28);
		serial_puts("\tG<addr> : exec at addr in\n\r",28);
		serial_puts("\tR<addr> : display addr in\n\r",28);
		serial_puts("\t <addr> : 0x........\n\n\r",25);

 		receive_char = serial_getc();
		switchOnOff(4,OFF);

		switch(receive_char)
		{
		case 'L':
		case 'l':
		
			switchOnOff(1, ON);
		  
			addr = getAddress();

			if(testAddress(addr))
				storeBytes((unsigned char *) addr);
			else
				switchOnOff(4,ON);

			switchOnOff(1,OFF);

			break;

		case 'G':
		case 'g':
			switchOnOff(2,ON);
			addr = getAddress();
			asm("mov pc, %[value]":: [value]"r"(addr));
			break;

		case 'R':
		case 'r':
			switchOnOff(2,ON);
			addr = getAddress();
			serial_puts("\n\r-> ",5);
			intToHexa(*(unsigned long *)addr);
			serial_puts("\n\r",2);
			break;
		}
	}
	return 0;
}


unsigned long getAddress()
{
	unsigned short i;
	char receive[10];

	for(i=0; i<10; i++)
	{
		receive[i] = serial_getc();
	}
	return ((receive[0] == '0') & (receive[1] == 'x')) ? asciiToHex(receive + 2) : 0;
}




inline unsigned short testAddress(unsigned long addr)
{
	return ((addr > BSS_END) && (addr < STACK_END));
}


void storeBytes(unsigned char * addr)
{
	char getReturn;

	while((unsigned long)addr>BSS_END)
	{

		if(!serial_getcWithTimer(&getReturn))
		{
			serial_puts("Time OUT\n\n\r",11);
			break;
		}

		*addr=getReturn;
		addr++;
	}
}
