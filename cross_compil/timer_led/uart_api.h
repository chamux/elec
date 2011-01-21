#ifndef _UART_API_
#define _UART_API_

void serial_init();

void serial_putc(char c);

char serial_getc();

void serial_puts(char * s);

inline void serial_newLine();

#endif
