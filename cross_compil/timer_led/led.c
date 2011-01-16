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
		wait(1000);//1000*1ms
	}
}

void switchAllOnState(short state)
{
	modif(&PORTC,MASQUE_C,state);
	modif(&PORTE,MASQUE_E,state);
}

void switchOnOff(unsigned short ledNb, short state) 
{
	if(ledNb!=4)
		modif(&PORTC,((unsigned short)1)<<ledNb,state);
	else
		modif(&PORTE,MASQUE_E,state);
}

void modif(volatile unsigned long *registre, unsigned long masque, short state)
{
	if(state==ON)
		*registre=(*registre)|masque;
	else
		*registre=(*registre)&(~masque);
}
