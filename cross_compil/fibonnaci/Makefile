PREFIX = arm-none-eabi-
LDSCRIPT = script.ld
CC = $(PREFIX)gcc
CFLAGS = -c -fomit-frame-pointer -Werror -Wall -O2 

LD = $(PREFIX)ld
LDFLAGS = -cref -M > $(EXE).map -T $(LDSCRIPT)

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))

EXE = fibo


all: Makefile $(EXE)

compile: $(OBJ)

$(EXE): $(OBJ) 
	$(LD) $(LDFLAGS) $^ -o $@

dump: $(EXE) $(LDSCRIPT)
	$(PREFIX)objdump -d $< > $<.lst

%.o: %.c 
	$(CC) $(CFLAGS) $<

clean:
	rm -f *~ $(OBJ) $(EXE).map $(EXE).lst $(EXE) *.swp 
