#include "test.h"

using func_using = void(*)(int, int);
void func_using_A(int a, int b) {
  std::cout << "__FUNCTION__" << std::endl;
  std::cout << "a=" <<a << ",b=" <<b << std::endl;
}

void func_using_B(func_using f) {
  std::cout<< __FUNCTION__ << std::endl;
  f(1, 2);
}

void test_using() {
  func_using_B(func_using_A);
}