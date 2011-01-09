
MEMORY {
  ram : ORIGIN = 0x0c000000, LENGTH = 8M
}

SECTIONS
{
  .text : { 
    crt0.o(.text)
    *(.text) 
  } > ram

  .data : {
    *(.data)
    *(*rodata*)
  } > ram

  .bss : {
    *(.bss) *(COMMON)
  } > ram

  size_data = SIZEOF(.data);
  size_bss = SIZEOF(.bss);

}
