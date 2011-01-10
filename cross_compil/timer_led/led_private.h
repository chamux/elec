#ifndef LED_PRIVATE_H
#define LED_PRIVATE_H

#define PORTC (*(volatile unsigned long *) 0x1d20014)
#define PORTE (*(volatile unsigned long *) 0x1d2002c)

#define MASQUE_C 0xFFFFFFF1
#define MASQUE_E 0xFFFFFFDF


#endif
