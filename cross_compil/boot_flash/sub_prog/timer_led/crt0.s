.global _start
.global _exit	
_start:
   ldr r13,=0x0c7ffffc
   bl fill_bss
   bl main
_exit:
   b _exit
