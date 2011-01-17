#ifndef BOOT_H
#define BOOT_H

#define STACK_END 0x0cefffff
#define BSS_END (unsigned long)& _bss_end_
extern char _bss_end_;

void mainBoot();
unsigned long getAddress();
inline unsigned short testAddress(unsigned long addr);
void storeBytes(unsigned char *addr);


#endif
