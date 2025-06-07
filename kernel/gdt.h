#include "stdint.h" 
struct gdt_entry {
    uint16_t limit;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t flags;
    uint8_t base_high;
}__attribute__((packed));
struct gdtr {
    uint16_t limit;
    uint32_t base;
} __attribute__ ((packed));
void setGdtGate(uint32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);
void gdtinit();
void gdtflush(uint32_t sans);
void tssflush();
#define GDTBASE    0x00000800
