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

EXE = hello


all: $(EXE) dump

compile: $(OBJ)

$(EXE): $(OBJ) 
	$(LD) $(LDFLAGS) $^ -o $@

dump: $(EXE) $(LDSCRIPT)
	$(PREFIX)objdump -d $< > $<.lst

clean:
	rm -f *~ $(OBJ) $(EXE).map $(EXE).lst $(EXE) *.swp 
