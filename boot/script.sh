#/opt/homebrew/bin/arm-none-eabi-gcc -c startup.s -o startup.o
#/opt/homebrew/bin/arm-none-eabi-gcc -c test.s -o test.o
#/opt/homebrew/bin/arm-none-eabi-gcc -c endianness.s -o end.o
#/opt/homebrew/bin/arm-none-eabi-gcc -c app.s -o tes.o
#/opt/homebrew/bin/arm-none-eabi-ld -T test.ld test.o tes.o startup.o end.o -o test.elf
#/opt/homebrew/bin/arm-none-eabi-objcopy -O binary test.elf test.bin


qemu-system-arm -M versatilepb -m 128M -nographic -kernel app.elf
