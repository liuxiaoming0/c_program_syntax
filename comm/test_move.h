#ifndef BBE551E5_13F4_4C1B_BC0F_9182DBB5D757
#define BBE551E5_13F4_4C1B_BC0F_9182DBB5D757
#include "test.h"

// 移动拷贝std::move，原有t中string被清空，疑问：是重新分配地址的
void test_std_move() {
  Item t = {1, "name", 100};
  // printf("t address = %p\n", &(t.name));
  // Item t_copy = t;
  Item t_copy = std::move(t);
  // printf("t_copy address = %p\n", &(t_copy.name));
  t_copy.print_item();
  t.print_item();
}

// perferct forward
namespace pf {
void func2(const int& i) { printf("r value\n"); }
void func2(int& i) { printf("l value\n"); }

template <typename T>
void func(T&& t) {
  // func2(std::forward<T>(t));
  func2(t);
}  // T&&自动匹配左右值
}  // namespace pf

void test_perfect_forward() {
  int a = 2;
  pf::func(a);
  pf::func(std::move(a));
  pf::func2(10);
}


#endif /* BBE551E5_13F4_4C1B_BC0F_9182DBB5D757 */
