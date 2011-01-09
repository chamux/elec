.global _start
_start:

   ldr r13,=0x0c7ffffc
   bl main
exit:
    b exit
