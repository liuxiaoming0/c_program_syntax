#ifndef D3C26ECF_D8DA_42B2_8929_87F29EEB9C7D
#define D3C26ECF_D8DA_42B2_8929_87F29EEB9C7D
#include "test.h"

// 任意类型std::any
void test_std_any() {
  // 初始化和运行时转换std::any_cast
  std::any s = "a";
  std::any ss = std::string("b");
  std::any i = std::make_any<int>(1);
  printf("string typeid(s) = %s\n", typeid(decltype(s)).name());
  printf("string s=%s, ss=%s, typeid(s) = %s\n", std::any_cast<const char*>(s),
         std::any_cast<std::string>(ss).c_str(), typeid(decltype(i)).name());
  printf("int i=%d, typeid(i) = %s\n", std::any_cast<int>(i), i.type().name());
  if (i.type() == typeid(int)) {
    std::cout << "true" << std::endl;
  }

  // 怎么转换函数？
  std::function f = []() -> int { return 1; };
  std::any fun = f;
  printf("func f(), type is [%s], ret = %d\n", fun.type().name(), f());

  // 类
  std::any c = Cprint();
  std::any_cast<Cprint>(c).printT();
  printf("test has_value = %d\n", c.has_value());
  int ii = 2;
  std::any im = std::move(ii);
  printf("test im = %d\n", std::any_cast<int>(im));
}

#endif /* D3C26ECF_D8DA_42B2_8929_87F29EEB9C7D */
