#include "stdint.h"
uint8_t inb(uint16_t port) {
  uint8_t ret;
  __asm__("in %%dx, %%al"
	  : "=a"(ret)
	  : "d" (port)
	  : "memory");
  return ret;
}
void outb(uint16_t port, uint8_t value) {
  __asm__("out %%al, %%dx"
	  : "a="(value)
	  : "d" (port)
	  : "memory");
}
void timer_wait(int time) {
  
}
void memset(void *dest, char val, uint32_t count) {
    char *temp = (char *)&dest;
  for (; count != 0; count --) {
    *temp++ = val;
  }
}
