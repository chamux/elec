#ifndef LED_PRIVATE_H
#define LED_PRIVATE_H

#define PORTC (*(volatile unsigned long *) 0x1d20014)
#define PORTE (*(volatile unsigned long *) 0x1d2002c)

#define MASQUE_C (unsigned long)0xE
#define MASQUE_E (unsigned long)0x20

void modif(volatile unsigned long *registre, unsigned long masque, long val);

#endif
