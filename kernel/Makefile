GCCFLAGS = -c -std=c99 -mno-red-zone -fno-pie -fno-stack-protector -m32
CC = gcc
AS = nasm
OBJ = main.o gdt.o disp.o gdtc.o stdio.o mainc.o
all:
	$(AS) -f elf32 main.s
	$(AS) -f elf32 gdt.s 
	$(CC) $(GCCFLAGS) main.c -o mainc.o
	$(CC) $(GCCFLAGS) disp.c
	$(CC) $(GCCFLAGS) gdt.c -o gdtc.o
	$(CC) $(GCCFLAGS) stdio.c
	ld main.o mainc.o disp.o gdt.o gdtc.o  stdio.o -T linker.ld -o zImage -m elf_i386
install:
	sudo cp zImage /run/media/rio/8A08-BADB/boot
	rm $(OBJ)
run:
	sudo qemu-system-x86_64 /dev/sdb


