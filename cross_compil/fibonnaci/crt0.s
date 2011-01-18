.global _start
.global _exit
_start:
   ldr r13,=0x0c7ffffc
   bl main
_exit:
   .word 0xdeeedeee

