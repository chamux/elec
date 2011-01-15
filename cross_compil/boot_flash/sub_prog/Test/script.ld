MEMORY {
  ram : ORIGIN = 0x0c100000, LENGTH = 7M
}

SECTIONS
{
  .text : { 
    *(.text) 
  } > ram

  .data : {
    *(.data)
    *(*rodata*)
  } > ram

  _bss_beginning_ = .;

  .bss : {
    *(.bss) *(COMMON)
  } > ram

  _bss_end_ = .;

  size_data = SIZEOF(.data);
  size_bss = SIZEOF(.bss);

}
