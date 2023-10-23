#ifndef F9099A2F_8B42_4E4E_BC22_85160F9E7DCE
#define F9099A2F_8B42_4E4E_BC22_85160F9E7DCE
#include "test.h"

// 测试CData模板类
void test_CData_template() {
  CData<Item> datas;
  for (int i = 5; i > 0; i--) {
    Item one{};
    one.id = i;
    one.name = "name";
    datas.Insert(one);
  }
  datas.Print();

  // 定义排序
  std::function<bool(const Item& left, const Item& right)> cmp;
  cmp = [&](const Item& left, const Item& right) -> bool {
    return left.id < right.id;  // 从小到大排序
  };
  datas.Sort(cmp);
  datas.Print();
  printf("test_CData_template, datas[%d].id=%d\n", 4, datas[4].id);
}


#endif /* F9099A2F_8B42_4E4E_BC22_85160F9E7DCE */
