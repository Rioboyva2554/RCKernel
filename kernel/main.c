#include "disp.h"
//#include "sound.h"
#include "gdt.h"
int main() {
  /*
    	  	mov word [0xb8000], 0x248 ;H
	mov word [0xb8002], 0x261 ;a
	mov word [0xb8004], 0x263 ;c
	mov word [0xb8006], 0x26b ;k
	mov word [0xb8008], 0x220 ;space
	mov word [0xb800a], 0x274 ;t
	mov word [0xb800c], 0x268 ;h
	mov word [0xb800e], 0x265 ;e
	mov word [0xb8010], 0x220 ;space
	mov word [0xb8012], 0x270 ;p
	mov word [0xb8014], 0x26c ;l
	mov word [0xb8016], 0x261 ;a
	mov word [0xb8018], 0x26e ;n
	mov word [0xb801a], 0x265 ;e
	mov word [0xb801c], 0x274 ;t
	mov word [0xb801e], 0x221 ;!
  */
  //gdtinit();
  println("Hacking your computer >:3");
  // beep();
  spinner();

}
