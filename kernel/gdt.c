#include "gdt.h"
#include "tss.h"
#include "stdint.h"
#include "stdio.h"
#include "disp.h"
struct gdt_entry blorp[6];
struct tss redspyinbase;
  struct gdtr losercity;
void setgdtgate(uint32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
    blorp[num].base_low = (base & 0xFF);
    blorp[num].base_middle = ((base >> 16) & 0xFF);
    blorp[num].base_high = ((base >> 24) & 0xFF);
  blorp[num].limit = (limit & 0xFFFF);
blorp[num].flags = ((limit >> 16) & 0xFFFF);
blorp[num].flags = (gran & 0xF0);
   blorp[num].access = access;
   return;
}
void writetss(uint32_t num, uint16_t ss0, uint32_t esp0) {
  uint32_t intruderalert = (uint32_t)&redspyinbase; //the pinnacle of comedy
  uint32_t limit = intruderalert + sizeof(redspyinbase);
  setgdtgate(num, intruderalert, limit, 0xE9, 0x00);
  memset(&redspyinbase, 0, sizeof(redspyinbase));
  redspyinbase.esp0 = esp0;
  redspyinbase.ss0 = ss0;
  redspyinbase.cs = 0x08 | 0x3;
  redspyinbase.ss = redspyinbase.ds = redspyinbase.es = redspyinbase.fs = redspyinbase.gs = 0x10 | 0x3;
}
void gdtinit() {
  losercity.base = (sizeof(struct gdt_entry) * 6) - 1;
  losercity.limit = (uint32_t)&blorp;
  // ( ͡° ͜ʖ ͡°)
 setgdtgate(0,0,0,0,0); //Null segment
setgdtgate(1,0,0xFFFFFFFF,0x9A,0xC);
   setgdtgate(2,0,0xFFFFFFFF,0x92,0xC);
setgdtgate(3,0,0xFFFFFFFF,0xFA,0xC);
setgdtgate(4,0,0xFFFFFFFF,0xF2,0xC);
setgdtgate(5,0,0xFFFFFFFF,0xF2,0xC);
//why is writetss causing a triple fault? 
//writetss(5, 0x10, 0x0);
       println("h");
 println("If you only see this it is GDT");
 gdtflush((uint32_t)&losercity);
 println(", however if you see this string it is TSS"); 
 //tssflush();
}
