#ifndef TIMER_H
#define TIMER_H

#define (*(volatile unsigned long *) 0x01d50030) TCNTB3		
#define (*(volatile unsigned long *) 0x01d50034) TCMPB3		//TCNTB3 is compared to this value
#define (*(volatile unsigned long *) 0x01d50008) TCON			//Setting-up of Timer
#define (*(volatile unsigned long *) 0x01d50038) TCNTO3		//Output of Timer 3
#define (*(volatile unsigned long *) 0x01d50000) TCFG0		//To configure prescaler value
#define (*(volatile unsigned long *) 0x01d50004) TCFG1		//To configure divider value
#define (*(volatile unsigned long *) 0x01d20028) PCONE		//[13:12] <= 10 to put TOUT3 on PE6

#define count_begin_100 41250
#define count_begin_1 8250


void wait100ms();
void wait(unsigned long time);
void wait1s();
void wait1ms();
void bip();


#endif
