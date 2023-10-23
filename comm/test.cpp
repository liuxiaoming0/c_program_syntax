#include "test.h"

// 函数指针
int callback(int a) { return a + 5; }
void test_func_as_args(func_callback f) {
  printf("test_func_as_args=%d\n", f(10));
  // test_func_as_args(callback); //调用
}