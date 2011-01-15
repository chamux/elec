.global _start
_start:

   bl fill_bss
   bl main
stop:
   mov pc,#0x0c000000
