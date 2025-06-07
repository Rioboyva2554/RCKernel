bits 32
section multiboot_header
    align 4
    dd 0x1BADB002
    dd 0x00000000
    dd -(0x1BADB002 + 0x00000000)
section .text	
global start
extern main	
extern println
start:
	cli
	mov esp, stack
	call main
	hlt
section .bss
RESB 8192
stack:


