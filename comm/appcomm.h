#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>

extern int32_t E_a;       // 默认有extern，全局变量
const int32_t E_b = 200;  // 默认没有extern，只在当前文件生效
static int32_t E_c = 1;

#ifndef LONG
typedef int64_t LONG;
#endif  // !LONG

struct Item {
  int32_t id;
  std::string name;
  int64_t amt;
  inline void print_item() noexcept { printf("id=%d, name=%s, amt=%ld\n", id, name.c_str(), amt); }
};

typedef std::vector<std::shared_ptr<Item>> VEC_INTEM_PTR;
typedef std::vector<Item> VEC_INTEM;
