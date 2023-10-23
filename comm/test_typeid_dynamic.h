#ifndef B7EE13BF_9E36_4AAF_BEF1_02766A72CA4C
#define B7EE13BF_9E36_4AAF_BEF1_02766A72CA4C
#include "test.h"

std::string Ccfg::cfg_path_ = "";

// 运行态打印迭代器类型typeid、类型转换
void test_map_type() noexcept {
  std::unordered_map<std::string, int32_t> datas;
  datas.insert(std::make_pair("order1", 1));
  datas.insert(std::make_pair("order2", 2));
  datas.insert(std::make_pair("order3", 3));

  using t = std::unordered_map<std::string, int32_t>::iterator;
  for (auto it = datas.begin(); it != datas.end(); it++) {
    std::cout << typeid(it).name();
    // std::cout << typeid(it - datas.begin()).name();
    printf("test_map_type, iterator type is = %d\n", typeid(it).name() == typeid(t).name());
  }

  // dymic类型转换
  // Ccfg* bCfg = new Ccfg(10);
  CIncomeCfg* iCfg = new CIncomeCfg(20);
  printf("test_map_type, icfg type is = %d\n",
         typeid(dynamic_cast<Ccfg*>(iCfg)).name() == typeid(iCfg).name());

  // const类型转换
  int n = 64;
  auto func = [&](int* pn) -> int { return *pn; };
  const int* pn = &n;
  printf("const trans:%d\n", func(const_cast<int*>(pn)));

  // 静态类型转换
  void* iiCfg = new CIncomeCfg(20);
  printf("test_map_type, icfg type is = %d\n",
         typeid(static_cast<Ccfg*>(iiCfg)).name() == typeid(iiCfg).name());
}

#endif /* B7EE13BF_9E36_4AAF_BEF1_02766A72CA4C */
