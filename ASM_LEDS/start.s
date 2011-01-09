.ARM            @ arm code not thumb
.section .text  @ we are in the text section

_start: .global _start @ linker entry point
        .global main   @ the main program
        b main
.END
