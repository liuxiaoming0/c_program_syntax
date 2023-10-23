#include "test.h"

template <int N>
class C {};
void test_constexpr() {
  auto add = [](int x) constexpr {
    // printf("add(x), x=%d\n", x); // 此处加上后参数不能传常数
    return 5 + x;
  };

  auto f = [&](const int x) {
    // C<x> c1;  // error: ‘x’ is not a constant expression
    C<add(6)> c2;
  };

  const int a = 5;      // semantics：only read variable & constant
  C<a> c1;              // constant
  *(int*)(&a) = 6;      // variable
  printf("a=%d\n", a);  // 5
  C<add(a)> c2;         // constexpr is constant, print of add function is not running

  const int* p = &a;
  printf("*p=%d\n", *p);  // 6
}