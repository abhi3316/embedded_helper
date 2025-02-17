CC = /opt/homebrew/bin/arm-none-eabi-gcc
AS = /opt/homebrew/bin/arm-none-eabi-as
LD = /opt/homebrew/bin/arm-none-eabi-ld
OC = /opt/homebrew/bin/arm-none-eabi-objcopy

ASM_SRC = boot.s startup.s lib.s 
SRC = endianness.c

ld_script = boot.ld
 
TARGET = app.elf

asm_src: ${ASM_SRC}
	${AS} ${ASM_SRC} -o app.o

app: ${SRC} asm_src
	${CC} -c ${SRC} -o app_en.o

bl: app 
	${LD} -T ${ld_script} app.o app_en.o -o ${TARGET}

all:bl
	${OC} -O binary ${TARGET} app.bin

# Clean up generated files
clean:
	rm -rf *.elf *.bin *.o endianness.s

.PHONY: all clean

