
/opt/homebrew/bin/arm-none-eabi-as startup.s -o startup.o
/opt/homebrew/bin/arm-none-eabi-as test.s -o test.o
/opt/homebrew/bin/arm-none-eabi-ld -T test.ld startup.o test.o -o test.elf
/opt/homebrew/bin/arm-none-eabi-objcopy -O binary test.elf test.bin

qemu-system-arm -M versatilepb -m 128M -nographic -kernel test.elf
