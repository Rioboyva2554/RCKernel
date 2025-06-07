#include "stdint.h"
unsigned char inb(uint16_t port);
void outb(uint16_t port, uint8_t value);
static void play_sound(uint32_t nFrequence);
static void nosound();
void beep();
		    
