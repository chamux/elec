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

	while(1)
	{
		serial_puts("\tL<addr> : data at addr in\n\r");
		serial_puts("\tG<addr> : exec at addr in\n\r");		
		serial_puts("\tR<addr> : display addr in\n\r");
		serial_puts("\t <addr> : 0x........\n\n\r\r");

		serial_puts("\tYou have 5 seconds to enter a character\n\r");

		if(serial_getcWithTimer5s(&receive_char))
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
					switchOnOff(4,ON);

				switchOnOff(1,OFF);

				break;

			case 'G':
			case 'g':
				switchOnOff(2,ON);
				f = (void *)getAddress();
				f();
				switchOnOff(2,OFF);
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
			case 'c':
			case 'C':
				chenillard();
				break;
			case 'b':
			case 'B':
				bip();
				break;
			case 'p':
			case 'P':
//poireau
				break;
			default:
				switchOnOff(4,ON);
				break;
			}
		}
		else
		{
			serial_puts("\t------------Jump in 0x03000------------\n\r");
			f=(void *)0x3000;
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
