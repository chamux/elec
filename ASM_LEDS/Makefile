SRC = $(wildcard *.s)
OBJ = $(patsubst %.s,%.o,$(SRC))

PREFIX = arm-none-eabi-
LD = $(PREFIX)ld
AS = $(PREFIX)as
LDFLAGS = -Ttext 0x0c200000
ASFLAGS = -g -mcpu=arm7tdmi
EXE = led

all:$(EXE)

$(EXE): $(OBJ)
	$(LD) $(LDFLAGS)  $^ -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -f *.o $(EXE) *~
