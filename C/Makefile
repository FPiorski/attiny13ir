PROG=stk500v2
PORT=/dev/ttyUSB0

all: main.hex

main.hex: main.o
	avr-objcopy -j .text -j .data -O ihex main.o main.hex

main.o: main.c
	avr-gcc -std=c11 -Wall -g -Os -mmcu=attiny13 -DF_CPU=75000 -o main.o main.c

#-B1024 required for the slow clock speeds we're using

flash: main.hex
	avrdude -p t13 -c $(PROG) -P $(PORT) -B 1024 -U flash:w:main.hex:i -F

fuses:
	avrdude -p t13 -c $(PROG) -P $(PORT) -B 1024 -U hfuse:w:0xFF:m -U lfuse:w:0x7A:m

clean:
	rm -f main.hex main.o

disassemble: main.o
	avr-objdump -d main.o
