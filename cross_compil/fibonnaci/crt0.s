.global _start
.global _exit
_start:
   ldr r13,=0x0c7ffffc
   bl main
_exit:
   ldr r0,=0xdeeedeee
   str r0, [pc,#4]
   nop
   nop
