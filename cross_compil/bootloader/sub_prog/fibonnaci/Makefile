PREFIX = arm-none-eabi-
LDSCRIPT = script.ld
CC = $(PREFIX)gcc
CFLAGS = -c -Werror -Wall -g

LD = $(PREFIX)ld
LDFLAGS = -cref -M > $(EXE).map -T $(LDSCRIPT)

ASFLAGS = -g -mcpu=arm7tdmi
AS = $(PREFIX)as
SRCC = $(wildcard *.c)
SRCS = $(wildcard *.s)
OBJ = $(patsubst %.c,%.o,$(SRCC))
OBJ += $(patsubst %.s,%.o,$(SRCS))

EXE = fibo_boot

all: Makefile $(EXE) $(EXE).lst $(EXE).hex

compile: $(OBJ)

transmit: $(EXE).hex
	echo -n "L0x0c100000" > /dev/ttyS0
	sleep 0.1s
	cat $< > /dev/ttyS0



$(EXE): $(OBJ) 
	$(LD) $(LDFLAGS) $^ -o $@

%.lst: $(EXE) $(LDSCRIPT)
	$(PREFIX)objdump -d $< > $@

%.hex: $(EXE)
	 $(PREFIX)objcopy --input-target=elf32-littlearm --output-target=binary $< $@  

clean:
	rm -f *~ $(OBJ) $(EXE).map $(EXE).lst $(EXE).hex $(EXE) *.swp 

