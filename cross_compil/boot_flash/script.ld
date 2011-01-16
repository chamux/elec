MEMORY {
  flash : ORIGIN = 0x00000000, LENGTH = 2M
  ram : ORIGIN = 0x0c000000, LENGTH = 8M
}

SECTIONS
{
  .text : { 
    crt0.o(.text)
    *(.text) 
  } > flash

  _data_beginning_flash_ = .;

  . = 0x0c000000;

  _data_beginning_ram_ = .;

  .data : {
    *(.data)
    *(*rodata*)
  } > flash

  . = 0x0c000000 + SIZEOF(.data);

  _data_end_ram_ = .;

  _bss_beginning_ = .;

  .bss : {
    *(.bss) *(COMMON)
  } >ram

  _bss_end_ = _bss_beginning_ + SIZEOF(.bss);

  size_data = SIZEOF(.data);
  size_bss = SIZEOF(.bss);

}
