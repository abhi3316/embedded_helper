The complete idea of the project

This project will run in 2 modes.

	1. Basic mode: 
		The software block present in basic mode are:
		1) bootloader
		2) application

		The entire system runs on qemu emulator, the bootloader have
		to run first, to properly bring up the application.
		The software targets only arm based bootloader.

	2. Linux Mode:
		The software block present in the linux mode are:
		1)bootloader
		2)Linux
		3)application.

		The custom bootloader developed should bring up the linux and 
		application in this case, also it should run in qemu.


