.global _start
_start:

   ldr r13,=0x0c7ffffc
   @bl fill_bss
   bl main
stop:
    b stop
