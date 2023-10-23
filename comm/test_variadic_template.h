#ifndef D6F28F6A_53AF_43FB_A6AE_8DF5D02B14ED
#define D6F28F6A_53AF_43FB_A6AE_8DF5D02B14ED
#include "test.h"

template<typename T, typename ...Args>
void print(T first, Args... args) {
  if constexpr(sizeof...(Args) == 0) {
    std::cout << first << std::endl;
  } else {
    std::cout << first << std::endl;
    print(args...);
  }
}

void test_variadic_template() {
  print(1, "hello", 2, 1.23, "hello");
}

#endif /* D6F28F6A_53AF_43FB_A6AE_8DF5D02B14ED */
