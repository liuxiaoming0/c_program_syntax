#ifndef FFF0C164_F305_4362_92A4_0CD63465A209
#define FFF0C164_F305_4362_92A4_0CD63465A209
#include "test.h"

#define PRINTF_VARINT_ADDRESS(name, v) printf("%s: address=%p, value=%d\n", name, &v, v)

#define PRINTF_PTR_ADDRESS(name, ptr) \
  printf("%s: address=%p, value=%p, ptr_value=%d\n", name, &ptr, ptr, *ptr)

#define PRINTF_DOUBLE_PTR_ADDRESS(name, ptr) \
  printf("%s: address=%p, value=%p, ptr_value=%p, doube_value=%d\n", name, &ptr, ptr, *ptr, **ptr)
#define PRINTF_REGEX printf("----------------------------\n");

void test_double_ptr() {
  int a = 10;
  int A = 12;
  int* B = &A;
  int** C = &B;
  auto show = [&]() {
    PRINTF_VARINT_ADDRESS("A", A);
    PRINTF_PTR_ADDRESS("B", B);
    PRINTF_DOUBLE_PTR_ADDRESS("C", C);
    PRINTF_REGEX;
  };

  show();
  auto func1 = [&](int* p) { p = &a; };
  auto func2 = [&](int** p) { *p = &a; };
  func1(B);
  show();
  func2(C);
  show();
}

#endif /* FFF0C164_F305_4362_92A4_0CD63465A209 */
