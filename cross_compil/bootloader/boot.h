#ifndef BOOT_H
#define BOOT_H

#define STACK_END 0x0cefffff
extern char _ram_beginnig_, _ram_end_, _bss_end_;

void mainBoot();
unsigned long getAddress();
inline unsigned short testAddress(unsigned long addr);
void storeBytes(unsigned long addr);


#endif
