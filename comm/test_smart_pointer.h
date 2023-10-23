#ifndef B7A19C10_063A_4DA4_9A55_2D82A634B0D9
#define B7A19C10_063A_4DA4_9A55_2D82A634B0D9
#include "test.h"
using std::shared_ptr;
using std::unique_ptr;

// smart pointer: shared_ptr
void test_ptr1() {
  LINE("normal");  // 第1部分-normal
  int i = 1;       //
  int ia[] = {1, 2, 3, 4};
  auto c = "t";
  int* np1 = ia;
  int* np2 = &i;  // 在栈上分配
  const char** np3 = &c;
  np1[2] = 30;  // *(np1 + 2) = 30;
  printf("np1=%p, *np1=%d, np1[2]=%d, *np2=%d, *np3=%s\n", np1, *np1, np1[2], *np2, *np3);
  np1 = nullptr;
  printf("np1=%p\n", np1);  // 使用*np1直接coredump

  LINE("share ptr (int)");                // 第2部分-shareptr
  std::shared_ptr<int> sp1(new int(10));  // 在堆上分配
  std::shared_ptr<int> sp2 = std::make_shared<int>(20);
  std::shared_ptr<int> sp3(sp2);
  printf("sp2=%d, sp3=%d, sp2.cnt=%lu, sp3.cnt=%lu\n", *sp2, *sp3, sp2.use_count(),
         sp3.use_count());

  *sp3 = 21;
  printf("sp2=%d, sp3=%d, sp2.cnt=%lu, sp3.cnt=%lu\n", *sp2, *sp3, sp2.use_count(),
         sp3.use_count());

  sp2.reset();
  printf("sp2.cnt=%lu, sp3.cnt=%lu\n", sp2.use_count(), sp3.use_count());

  std::shared_ptr<int> sp4(std::move(sp3));
  // printf("sp3=%d\n", *sp3);  // coredump
  printf("sp3.cnt=%lu, sp4.cnt=%lu\n", sp3.use_count(), sp4.use_count());

  LINE("share ptr (int[])");  // 第3部分-shareptr
  std::shared_ptr<int[]> ap1(new int[10]{2,3,4},
                             [](int* p) { delete[] p; });  //  c11后不必设置数组缺省的析构
  ap1[0] = 100;
  printf("ap1[0]=%d, ap1[1]=%d\n", ap1[0], ap1[1]);
}

// unique_ptr
void test_ptr2() {
  int* up1 = new int{10};
  auto up2 = std::make_shared<int>(10);
  // std::weak_ptr up3(up2);  // can`t created direct

  auto up4 = new Cprint();
  std::unique_ptr<Cprint> up5(new Cprint());
  auto up6 = std::make_unique<Cprint>();
  std::unique_ptr<Cprint> up7(std::move(up4));  // ownership move only way，remain unique

  // printf("sizeof(up1)=%lu, sizeof(up2)=%lu, sizeof(up3)=%lu\n", sizeof(up1), sizeof(up2), sizeof(up3));
  RELASE_PTR(up1);
}

// smart_ptr as args of function
void test_ptr3() {
  Item t = {1, "d", 100};
  auto fp1 = std::make_shared<Item>(t);
  auto fp2 = &t;
  // auto func1 = [](std::shared_ptr<Item> p) -> void { p->print_item(); };
  auto func = [](auto p) void {  // 这里的->可有可无
    if (typeid(decltype(p)) == typeid(std::make_shared<Item>()))
      p->print_item();
    else if (typeid(decltype(p)) == typeid(Item*))
      p->print_item();
    else
      dynamic_cast<Item*>(p)->print_item();
  };

  // func(fp1); // cannot dynamic_cast ‘p’ (of type ‘class std::shared_ptr<Item>’) to type ‘struct
  // Item*’
  func(fp2);
  // std::shared_ptr<Item>(fp2); // error
  printf("typeid(decltype(fp1))=%s, typeid(decltype(fp2))=%s\n", typeid(decltype(fp1)).name(),
         typeid(decltype(fp2)).name());
}

// shared_ptr loop reference
void test_ptr4() {
  // define class
  class B;
  struct A {
    std::shared_ptr<B> b;
    A() { std::cout << __FUNCTION__ << std::endl; }
    ~A() { std::cout << __FUNCTION__ << std::endl; }
  };
  struct B {
    std::shared_ptr<A> a;  // resource leak, destructor isn`t called
    // std::weak_ptr<A> a;  // ok
    B() { std::cout << __FUNCTION__ << std::endl; }
    ~B() { std::cout << __FUNCTION__ << std::endl; }
  };

  // std::shared_ptr<A> pa(new A()); // not split two statement, it`s ok
  {
    auto pa = std::make_shared<A>();  // suggest method
    auto pb = std::make_shared<B>();
    pa->b = pb;
    pb->a = pa;
    // printf("pa.cnt=%lu, pb.cnt=%lu\n", pa.use_count(), pb.use_count());
  }
  cout << "test" << endl;
  // pa.reset();
}

void test_ptr5() {
  std::auto_ptr<int> p1(new int(10));
  auto f = [](std::auto_ptr<int> p) {
    if (p.get() == nullptr) cout << "p is nullptr" << std::endl;
    else cout << "*p=" << *p << std::endl;
  };
  f(p1);
  if (p1.get() == nullptr) cout << "p1 is nullptr" << std::endl;
  else cout << "*p1=" << *p1 << std::endl;
}


#endif /* B7A19C10_063A_4DA4_9A55_2D82A634B0D9 */
