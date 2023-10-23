#include "test.h"

// 编译时类型自动推导
void test_decltype() {
  // 1)自动推导类型
  int i = 12;
  decltype(i) cnt;
  printf("cnt type is int? %d\n", typeid(cnt) == typeid(int));
  // 2)二种方法定义类型
  Item t{};
  // using item = decltype(t);
  typedef decltype(t) item;
  item data{};
  data.id = 1;
  printf("data type is Item? %d\n", typeid(data) == typeid(Item));

  // 3)泛型自动推导类型
#if 0
    template <typename T1, typename T2>
    auto multi(const& T1 x, const& T2 y)->decltype(x*y) {
        return x*y;
    }
#endif
}