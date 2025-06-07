#include "stdint.h"
void timer_wait(int time);
void outb(uint16_t port, uint8_t value);
uint8_t inb(uint16_t port);
void memset(void *dest, char val, uint32_t count);
