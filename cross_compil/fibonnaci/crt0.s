.global _start
_start:

   ldr r13,=0x0c7ffffc
   bl main
exit:
   ldr r0,=0xdeeedeee
	@str r0, [pc,#-8]
	b exit	
