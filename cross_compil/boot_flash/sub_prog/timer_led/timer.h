#ifndef TIMER_H
#define TIMER_H

//Timer3 : bip
#define TCNTB3 (*(volatile unsigned long *) 0x01d50030) 
#define TCMPB3 (*(volatile unsigned long *) 0x01d50034) 	//TCNTB3 is compared to this value
#define TCON (*(volatile unsigned long *) 0x01d50008) 		//Setting-up of Timer
#define TCNTO3 (*(volatile unsigned long *) 0x01d50038) 	//Output of Timer 3
#define TCFG0 (*(volatile unsigned long *) 0x01d50000) 		//To configure prescaler value
#define TCFG1 (*(volatile unsigned long *) 0x01d50004) 		//To configure divider value
#define PCONE (*(volatile unsigned long *) 0x01d20028) 		//[13:12] <= 10 to put TOUT3 on PE6

//Timer0 : wait
#define TCNTB0 (*(volatile unsigned long *) 0x01d5000c) 
#define TCNTO0 (*(volatile unsigned long *) 0x01d50014)

#define COUNT_100 20625
#define PRESC_100 0x1300
#define DIV_100 0x3000


#define COUNT_1 8250
#define PRESC_1 0
#define DIV_1 0x2000

#define COUNT_1000 8056
#define PRESC_1000 0xff00
#define DIV_1000 0x4000

#define COUNT_5000 51562
#define PRESC_5000 0xc700
#define DIV_5000 0x4000

#define INVERTER 0x40000


void init_timer0(unsigned long div,    
		 unsigned long presc,
		 unsigned long count);

void wait();
void wait_change_count(unsigned long count);

void bip_config(unsigned long div,    
	 unsigned long presc,
         unsigned long count);

void bip_stop();

void bip_start();

void bip_end();

void bip_change_count(unsigned long count);

#endif
