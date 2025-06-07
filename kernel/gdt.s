global gdtflush
	global tssflush
	extern losercity
gdtflush:	
	lgdt [losercity]
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp 0x08:flush2
flush2:	
	ret
tssflush:
	mov ax, 0x2B
	ltr ax
	ret
