PREFIX = arm-none-eabi-
LDSCRIPT = script.ld
CC = $(PREFIX)gcc
CFLAGS = -c -Werror -Wall -g -O2

LD = $(PREFIX)ld
LDFLAGS = -cref -M > $(EXE).map -T $(LDSCRIPT)

XFLAG=--input-target=elf32-littlearm --output-target=binary

ASFLAGS = -g -mcpu=arm7tdmi
AS = $(PREFIX)as
SRCC = $(wildcard *.c)
SRCS = $(wildcard *.s)
OBJ = $(patsubst %.c,%.o,$(SRCC))
OBJ += $(patsubst %.s,%.o,$(SRCS))

EXE = fibo

all: $(EXE) $(EXE).lst

compile: $(OBJ)

program: $(EXE).hex
	echo -n "L0x0c100000" > /dev/ttyS0
	sleep 0.5s
	cat $< > /dev/ttyS0
	sleep 4s
	echo -n "G0x0c100000" > /dev/ttyS0

%.hex: $(EXE)
	 $(PREFIX)objcopy $(XFLAG) $< $@  

$(EXE): $(OBJ) $(LDSCRIPT) Makefile
	$(LD) $(LDFLAGS) $(OBJ) -o $@

%.lst: $(EXE) $(LDSCRIPT) Makefile
	$(PREFIX)objdump -d $< > $@

clean:
	rm -f *~ $(OBJ) $(EXE).map $(EXE).lst $(EXE) *.swp 
