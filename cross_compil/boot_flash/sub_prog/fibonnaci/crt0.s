.global _start
.global _exit
_start:
   bl main
_exit:
   ldr pc,=0x0

