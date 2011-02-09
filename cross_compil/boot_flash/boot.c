#include "uart_api.h"
#include "timer.h"
#include "led.h"
#include "convert.h"
#include "boot.h"

int test = 45;

int main()
{
	char receive_char;
	unsigned long addr;
	void (*f)(void);

	serial_init();
	serial_puts("BOOTLOADER by Chazot Bertrand & Mokrani Samuel !!\n\r"); 
	switchAllOnState(OFF);

	init_timer0(0x4, 0xc7, 51562);

	while(1)
	{
		serial_puts("\tL<addr> : data at addr in\n\r");
		serial_puts("\tG<addr> : exec at addr in\n\r");		
		serial_puts("\tR<addr> : display addr in\n\r");
		serial_puts("\t <addr> : 0x........\n\n\r\r");

		serial_puts("\tYou have 5 seconds to enter a character\n\r");

		if(serial_getcWithTimer(&receive_char))
		{
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
				switchOnOff(3,ON);
				addr = getAddress();
				serial_puts("\n\r-> ");
				intToHexa(*(unsigned long *)addr);
				serial_puts("\n\r");
				switchOnOff(3,OFF);
				break;
			}
		}
		else
		{
			serial_puts("\t------------Jump in 0x030000------------\n\r");
			f=(void *)0x30000;
			f();
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

	init_timer0(0x4,0xff,COUNT_1000);

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

	init_timer0(0x4, 0xc7, 51562);
}
