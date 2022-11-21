COMMON_OBJECTS  = main.o
CPU      	= msp430g2553
CFLAGS		= -mmcu=${CPU} -0s -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC		= mps430-elf-gcc # C COMPILER
AS		= mps430-elf-gcc -mmcu=${CPU} -c

all: toy.elf

toy.elf ${COMMON_OBJECTS}
