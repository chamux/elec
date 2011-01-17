
MEMORY {
  flash : ORIGIN = 0x00000000, LENGTH = 2M
  ram : ORIGIN = 0x0c000000, LENGTH = 8M
}

SECTIONS
{
  .text : { 
    crt0.o(.text)
    *(.text) 
  } >flash

  .rodata : {
    *(.rodata*)
  } >flash

  _data_beginning_flash_ = .;


  .data : {
    _data_beginning_ram_ = .;
    *(.data)
    _data_end_ram_ = .;
  } >ram AT>flash

  

  

  .bss : {
    _bss_beginning_ = .;
    *(.bss) *(COMMON)
    _bss_end_ = .;
  } >ram

  size_data = SIZEOF(.data);
  size_bss = SIZEOF(.bss);

  __boot_linux  = 0x3000;

}
