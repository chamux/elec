PREFIX = arm-none-eabi-
LDSCRIPT = script.ld
CC = $(PREFIX)gcc
CFLAGS = -c -Werror -Wall -O2

LD = $(PREFIX)ld
LDFLAGS = -cref -M > $(EXE).map -T $(LDSCRIPT)

ASFLAGS = -mcpu=arm7tdmi
AS = $(PREFIX)as
SRCC = $(wildcard *.c)
SRCS = $(wildcard *.s)
OBJ = $(patsubst %.c,%.o,$(SRCC))
OBJ += $(patsubst %.s,%.o,$(SRCS))

EXE = boot

all: $(EXE) $(EXE).lst

compile: $(OBJ)

$(EXE): $(OBJ) $(LDSCRIPT) Makefile
	$(LD) $(LDFLAGS) $(OBJ) -o $@

%.lst: $(EXE) $(LDSCRIPT) Makefile
	$(PREFIX)objdump -d $< > $@

clean:
	rm -f *~ $(OBJ) $(EXE).map $(EXE).lst $(EXE) *.swp *.d

################################################################################
# Gestion des dépendances

ifneq "$(MAKECMDGOALS)" "clean" 

-include $(patsubst %.c,%.d,$(SRCC))

%.d : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -MM -MF $@ -MP -MT $(patsubst %.c,%.o,$<) $<
endif
