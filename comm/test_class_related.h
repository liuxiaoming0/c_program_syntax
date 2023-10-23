#include "test.h"

// 测试Cprint类，移动构造函数，编译器优化关闭：-fno-elide-constructors
void test_Cprint_class() {
  Item t{};
  std::string seg = "========";
  auto print = [&](const std::string name) {
    printf("%s [%s] %s \n", seg.c_str(), name.c_str(), seg.c_str());
  };

#if 1
  Cprint p;  // 构造->析构
  print("Cprint p");

  Cprint p_move(std::move(t));  // 构造->析构
  print("Cprint p(std::move(t))");

  Cprint p1(t);  // 构造->构造->赋值->析构->析构
  Cprint p2;
  p2 = p1;
  print("Cprint p2; p2=p1");
#endif

#if 0
  Cprint p1(t);  // 构造->移动拷贝析构->析构->析构，不能节省一次拷贝，只是转移所有权
  Cprint p2(std::move(p1));
  print("Cprint p2=p1");

  Cprint p1(t);// 构造->拷贝析构->析构->析构
  Cprint p2(p1);
  print("Cprint p2=p1");
#endif
}

// virtual destruct , explicit
void test_csprint_class() {
  Cprint c;  // 基类和派生类析构都被调用
  Cprint* p1 = new CSprint;
  delete p1;  // 若基类析构无virtual，只基类的析构被调用

  Item t = {1, "en", 100};
  // Cprint p2 = t; // explicit 不允许隐形转换
}

void test_class_A() {
  Cprofile c(__FUNCTION__);
  A a1;  // need default
  sleep(3);
  // A a2(a1);  // error, has deleted
}

// friend class
void fri_func(const Cprint& c) {
  printf("CShow(), name=%s, id=%d, amt=%ld\n", c.data_.name.c_str(), c.data_.id, c.data_.amt);
}
void test_class_friend() {
  Item t = {1, "bai", 1000};  // friend class
  auto p = std::make_shared<Cprint>(std::move(t));
  CShow::getPrintItem(p);

  fri_func(*p);  // friend func

  auto p1 = std::make_shared<CShow>(5);  // friend class member func
  CShow_one s;
  s.showInt(p1);
}