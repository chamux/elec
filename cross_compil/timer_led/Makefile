PREFIX = arm-none-eabi-
LDSCRIPT = script.ld
CC = $(PREFIX)gcc
CFLAGS = -c -Werror -Wall -g -O2

LD = $(PREFIX)ld 
LDFLAGS = -cref -M > $(EXE).map -T $(LDSCRIPT)

ASFLAGS = -g -mcpu=arm7tdmi
AS = $(PREFIX)as
SRCC = $(wildcard *.c)
SRCS = $(wildcard *.s)
OBJ = $(patsubst %.c,%.o,$(SRCC))
OBJ += $(patsubst %.s,%.o,$(SRCS))

EXE = led

all: $(EXE) $(EXE).lst

compile: $(OBJ)

$(EXE): $(OBJ) $(LDSCRIPT) Makefile
	$(LD) $(LDFLAGS) $(OBJ) -o $@

%.lst: $(EXE) $(LDSCRIPT) Makefile
	$(PREFIX)objdump -d $< > $@

clean:
	rm -f *~ $(OBJ) $(EXE).map $(EXE).lst $(EXE) *.swp 
