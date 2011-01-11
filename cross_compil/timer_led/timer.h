#ifndef TIMER_H
#define TIMER_H

#define TCNTB3 (*(volatile unsigned long *) 0x01d50030) 
#define TCMPB3 (*(volatile unsigned long *) 0x01d50034) 		//TCNTB3 is compared to this value
#define TCON (*(volatile unsigned long *) 0x01d50008) 			//Setting-up of Timer
#define TCNTO3 (*(volatile unsigned long *) 0x01d50038) 		//Output of Timer 3
#define TCFG0 (*(volatile unsigned long *) 0x01d50000) 		//To configure prescaler value
#define TCFG1 (*(volatile unsigned long *) 0x01d50004) 		//To configure divider value
#define PCONE (*(volatile unsigned long *) 0x01d20028) 		//[13:12] <= 10 to put TOUT3 on PE6

#define count_begin_100 20625
#define count_begin_1 8250


void wait100ms();
void wait(unsigned long time);
void wait1s();
void wait1ms();
void bip();


#endif
