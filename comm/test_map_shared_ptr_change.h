#ifndef E2E3F416_011A_4499_9E46_2720DFDA3787
#define E2E3F416_011A_4499_9E46_2720DFDA3787
#include "test.h"

// 公共函数
void print_vec(VEC_INTEM vecItem) noexcept {
  for (auto& one : vecItem) {
    one.print_item();
  }
}

void print_vec(VEC_INTEM_PTR vecItemPtr) noexcept {
  for (const auto& one : vecItemPtr) {
    printf("id=%d, name=%s, amt=%ld\n", one->id, one->name.c_str(), one->amt);
  }
}

// 测试map指针修改
void change_map_ptr(VEC_INTEM_PTR vecItemPtr) noexcept {
  for (const auto& one : vecItemPtr) {
    one->name = "name_change";
  }
}

int test_map_ptr() {
  VEC_INTEM_PTR vecItemPtr;
  for (int i = 0; i < 5; i++) {
    std::shared_ptr<Item> one = std::make_shared<Item>();
    one->id = i;
    one->name = "name";
    one->amt = i + 100;
    vecItemPtr.emplace_back(one);
  }
  print_vec(vecItemPtr);
  change_map_ptr(vecItemPtr);
  print_vec(vecItemPtr);
  return 1;
}

#endif /* E2E3F416_011A_4499_9E46_2720DFDA3787 */
