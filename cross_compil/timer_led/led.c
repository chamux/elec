#include "led_private.h"
#include "led.h"
#include "timer.h"


void chenillard()
{
	unsigned short currentLed=4;

	switchAllOnState(OFF);

	while(1)
	{
		switchOnOff(currentLed,OFF);
		currentLed=(currentLed%4)+1;
		switchOnOff(currentLed,ON);
		//wait(5);//5*100ms
		wait100ms();
		wait100ms();
		wait100ms();
		wait100ms();
		wait100ms();
		wait100ms();
		wait100ms();
		wait100ms();
		wait100ms();
		wait100ms();
		wait100ms();
		wait100ms();
		wait100ms();
	}
}

void switchAllOnState(short state)
{
	modif(&PORTC,MASQUE_C,(state==ON)?0xE:0x0);
	switchOnOff(4,state);
}

void switchOnOff(unsigned short ledNb, short state) 
{
	if(ledNb!=4)
		modif(&PORTC,MASQUE_C ,(state==ON)?((unsigned short)1)<<ledNb:0);
	else
		modif(&PORTE,MASQUE_E,(state==ON)?0x20:0);
}

void modif(volatile unsigned long *registre, unsigned long masque, long val)
{
	*registre=(*registre&masque)|val;
}

//get state ? retoune val courante
