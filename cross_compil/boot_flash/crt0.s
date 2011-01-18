.global _start

_start:

  @CPSR
  @ldr r0,=0x800000d3
  @msr cpsr,r0


  @WTCON
  ldr r0,=0x01d30000
  ldr r1,=0
  str r1, [r0]

  @INTMSK
  ldr r0,=0x01e0000c
  ldr r1,=0x03fffeff
  str r1, [r0]

  @INTCON
  ldr r0,=0x01e00000
  ldr r1,=0x5
  str r1, [r0]

  @LOCKTIME
  ldr r0,=0x01d8000c
  ldr r1,=0xf0
  str r1, [r0]

  @PLLCON
  ldr r0,=0x01d80000
  ldr r1,=0x0003a031
  str r1, [r0]

  @CLKCON
  ldr r0,=0x01d80004
  ldr r1,=0x00007ff8
  str r1, [r0]

  @PCONA
  ldr r0,=0x01d20000
  ldr r1,=0x000003ff
  str r1, [r0]

  @PDATB
  ldr r0,=0x01d2000c
  ldr r1,=0x7cf
  str r1, [r0]

  @PCONB
  ldr r0,=0x01d20008
  ldr r1,=0x07ff
  str r1, [r0]

  @PDATC
  ldr r0,=0x01d20014
  ldr r1,=0x0100
  str r1, [r0]

  @PCONC
  ldr r0,=0x01d20010
  ldr r1,=0xfff5ff54
  str r1, [r0]

  @PUPC
  ldr r0,=0x01d20018
  ldr r1,=0
  str r1, [r0]

  @PCOND
  ldr r0,=0x01d2001c
  ldr r1,=0x0000aaaa
  str r1, [r0]

  @PUPD
  ldr r0,=0x01d20024
  ldr r1,=0
  str r1, [r0]

  @PCONE
  ldr r0,=0x01d20028
  ldr r1,=0x00021569
  str r1, [r0]

  @PDATE
  ldr r0,=0x01d2002c
  ldr r1,=0
  str r1, [r0]

  @PUPE
  ldr r0,=0x01d20030
  ldr r1,=0
  str r1, [r0]

  @PCONF
  ldr r0,=0x01d20034
  ldr r1,=0x24900a
  str r1, [r0]

  @PUPF
  ldr r0,=0x01d2003c
  ldr r1,=0
  str r1, [r0]

  @PCONG
  ldr r0,=0x01d20040
  ldr r1,=0xff3c
  str r1, [r0]

  @PUPG
  ldr r0,=0x01d20048
  ldr r1,=0
  str r1, [r0]

  @SPUCR
  ldr r0,=0x01d2004c
  ldr r1,=0x6
  str r1, [r0]

  @INTMOD
  ldr r0,=0x01e00008
  ldr r1,=0
  str r1, [r0]

  @EXTINT
  ldr r0,=0x01d20050
  ldr r1,=0x00040440
  str r1, [r0]


  @memory init
  @---------------------------
  ldr r0,=0x01c80000
  ldr r1,=0x01001102
  str r1, [r0]

  ldr r0,=0x01c80004
  ldr r1,=0x00007ff4
  str r1, [r0]

  ldr r0,=0x01c80008
  ldr r1,=0x00000a40
  str r1, [r0]

  ldr r0,=0x01c8000c
  ldr r1,=0x00001480
  str r1, [r0]

  ldr r0,=0x01c80010
  ldr r1,=0x00007ffc
  str r1, [r0]

  ldr r0,=0x01c80014
  ldr r1,=0x00007ffc
  str r1, [r0]

  ldr r0,=0x01c80018
  ldr r1,=0x00000c40
  str r1, [r0]

  ldr r0,=0x01c8001c
  ldr r1,=0x00018004
  str r1, [r0]

  ldr r0,=0x01c80020
  ldr r1,=0x00000a40
  str r1, [r0]

  ldr r0,=0x01c80024
  ldr r1,=0x008603fb
  str r1, [r0]

  ldr r0,=0x01c80028
  ldr r1,=0x00000010
  str r1, [r0]

  ldr r0,=0x01c8002c
  ldr r1,=0x00000020
  str r1, [r0]

  ldr r0,=0x01c80030
  ldr r1,=0x00000020
  str r1, [r0]
  @end of memory init
  @-------------------------
	
	
  ldr r13,=_sp_begin_	
  bl fill_bss
  bl copy_data_ram
  bl main


	
