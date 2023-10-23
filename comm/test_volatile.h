#ifndef D61DB178_17A1_4931_B4A4_81234E3E47CB
#define D61DB178_17A1_4931_B4A4_81234E3E47CB
#include "test.h"

// volatile
void test_vola() {
  int i = 10;
  int a = i;
  printf("%d", a);
  // 如何用？
  /*
  asm("mov [ebp-4],20h");

  __asm {
    mov dword ptr [ebp-4], 20h
  }*/
  int b = i;
  printf("%d", b);
}

#endif /* D61DB178_17A1_4931_B4A4_81234E3E47CB */
