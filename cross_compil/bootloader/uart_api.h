#ifndef _UART_API_
#define _UART_API_

void serial_init();

void serial_putc(char c);

char serial_getc();

void serial_puts(char * s, short length);

short serial_getcWithTimer(char * charac);

inline void serial_newLine();

#endif
