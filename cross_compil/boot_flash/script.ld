
MEMORY {
  flash : ORIGIN = 0x00000000, LENGTH = 2M
  ram : ORIGIN = 0x0c000000, LENGTH = 8M
}

_sp_begin_ = 0x0c7ffffc;
_linux_kernel_ = 0x3000;

SECTIONS
{
  .text : { 
    crt0.o(.text)
    *(.text) 
  } >flash

  .rodata : {
    *(.rodata*)
    . = _linux_kernel_;
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

}
