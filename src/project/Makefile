# makfile configuration
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all:project.elf 

COMMON_OBJECTS  = screen.o wdt_handler.o main.o

libs:
	(cd timerLib && make install)
	(cd lcdLib && make install)

#additional rules for files
project.elf: ${COMMON_OBJECTS} switch_interrupt_handler-c.o buzzer_timer_interrupt-c.o 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd  

load: project.elf
	msp430loader.sh $^

clean:
	(cd timerLib && make install)
	(cd lcdLib && make install)
	rm -rf lib h
	rm -f *.o *.elf
