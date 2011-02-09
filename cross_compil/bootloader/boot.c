#include "uart_api.h"
#include "timer.h"
#include "led.h"
#include "convert.h"
#include "boot.h"

int main()
{
	char receive_char;
	unsigned long addr;
	void (*f)(void);

	serial_init();
	init_timer0(0x4,0xff,COUNT_1000);
	serial_puts("\n\n\rBOOTLOADER by Bertrand & Samuel\n\r"); 
	switchAllOnState(OFF);
 
	while(1)
	{
		serial_puts("\tL<addr> : data at addr in\n\r");
		serial_puts("\tG<addr> : exec at addr in\n\r");
		serial_puts("\tR<addr> : display addr in\n\r");
		serial_puts("\t <addr> : 0x........\n\n\r");

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
			{
				serial_puts("Wrong address : 0x");
				intToHexa(addr);
				serial_puts("\n\rIt must be between 0x");
				intToHexa(BSS_END);
				serial_puts(" and 0x");
				intToHexa(STACK_END);
				serial_newLine();
				serial_newLine();
				switchOnOff(4,ON);
			}

			switchOnOff(1,OFF);

			break;

		case 'G':
		case 'g':
			switchOnOff(2,ON);
			f = (void *)getAddress();
			f();
			break;

		case 'R':
		case 'r':
			switchOnOff(2,ON);
			addr = getAddress();
			serial_puts("\n\r-> ");
			intToHexa(*(unsigned long *)addr);
			serial_puts("\n\r");
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
			serial_puts("Time OUT\n\n\r");
			break;
		}

		*addr=getReturn;
		addr++;
	}
}
