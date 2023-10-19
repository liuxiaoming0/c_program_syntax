#include "test.h"

std::string Ccfg::cfg_path_ = "";

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
  for (auto& one : vecItemPtr) {
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

// 作用域、extern、static、const
void test_static() {
  // 局部静态变量，作用域后不释放
  auto func = []() -> int {
    static int32_t num = 100;
    return num++;
  };
  printf("test_status:first num=%d\n", func());
  printf("test_status:second num=%d\n", func());

  // const修饰的全局变量默认无extern，用包含头文件的方式使用
  printf("E_b=%d\n", E_b);
  // extern int E_g;
  // printf("test static, E_g=%d\n", E_g);

  // 两种方式的extern全局变量（头文件只能声明，若放在头文件定义，报错重复定义）
  extern int32_t E_d;  //作用域程序运行期都可访问！
  printf("E_d=%d\n", E_d);
  printf("E_a=%d\n", E_a);

  // 全局静态变量（默认对其他源文件隐藏，不会因为头文件定义而报错重复定义），用包含头文件的方式使用
  printf("E_c=%d\n", E_c);
  // printf("test extern, E_f=%d\n", F_f);

  // 类静态成员变量、类静态成员函数
  Ccfg cfg(10);
  // printf("class static, cnt=%d\n", cfg.print_cnt());
  cfg.set_path("/usr/local/bin");

  printf("class static, cnt=%s\n", cfg.print_path().c_str());
}

// volatile
void test_vola() {
  int i = 10;
  int a = i;
  printf("%d", a);
  // 如何用？
  /*
  asm("mov [ebp-4],20h");

  __asm {
    mov dword ptr [ebp-4], 20h
  }*/
  int b = i;
  printf("%d", b);
}

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
  printf("sp3=%d, sp2.cnt=%lu, sp3.cnt=%lu\n", *sp3, sp2.use_count(), sp3.use_count());

  std::shared_ptr<int> sp4(std::move(sp3));
  printf("sp3.cnt=%lu, sp4.cnt=%lu\n", sp3.use_count(), sp4.use_count());

  LINE("share ptr (int[])");  // 第3部分-shareptr
  std::shared_ptr<int[]> ap1(new int[10](),
                             [](int* p) { delete[] p; });  //  c11后不必设置数组缺省的析构
  ap1[0] = 100;
  printf("ap1[0]=%d, ap1[100]=%d\n", ap1[0], ap1[100]);
}

// unique_ptr
void test_ptr2() {
  int* up1 = new int(10);
  auto up2 = std::make_shared<int>(10);
  std::weak_ptr up3(up2);  // can`t created direct

  auto up4 = new Cprint();
  std::unique_ptr<Cprint> up5(new Cprint());
  auto up6 = std::make_unique<Cprint>();
  std::unique_ptr<Cprint> up7(std::move(up4));  // ownership move only way，remain unique

  printf("sizeof(up1)=%lu, sizeof(up2)=%lu, sizeof(up3)=%lu\n", sizeof(up1), sizeof(up2),
         sizeof(up3));
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
  struct B : public A {
    // std::shared_ptr<A> a;  // resource leak, destructor isn`t called
    std::weak_ptr<A> a;  // ok
    B() { std::cout << __FUNCTION__ << std::endl; }
    ~B() { std::cout << __FUNCTION__ << std::endl; }
  };

  // std::shared_ptr<A> pa(new A()); // not split two statement, it`s ok
  auto pa = std::make_shared<A>();  // suggest method
  auto pb = std::make_shared<B>();
  pa->b = pb;
  pb->a = pa;
  printf("pa.cnt=%lu, pb.cnt=%lu\n", pa.use_count(), pb.use_count());
  // pa.reset();
}

// 双重指针
#define PRINTF_VARINT_ADDRESS(name, v) printf("%s: address=%p, value=%d\n", name, &v, v)

#define PRINTF_PTR_ADDRESS(name, ptr) \
  printf("%s: address=%p, value=%p, ptr_value=%d\n", name, &ptr, ptr, *ptr)

#define PRINTF_DOUBLE_PTR_ADDRESS(name, ptr) \
  printf("%s: address=%p, value=%p, ptr_value=%p, doube_value=%d\n", name, &ptr, ptr, *ptr, **ptr)
#define PRINTF_REGEX printf("----------------------------\n");

void test_double_ptr() {
  int a = 10;
  int A = 12;
  int* B = &A;
  int** C = &B;
  auto show = [&]() {
    PRINTF_VARINT_ADDRESS("A", A);
    PRINTF_PTR_ADDRESS("B", B);
    PRINTF_DOUBLE_PTR_ADDRESS("C", C);
    PRINTF_REGEX;
  };

  show();
  auto func1 = [&](int* p) { p = &a; };
  auto func2 = [&](int** p) { *p = &a; };
  func1(B);
  show();
  func2(C);
  show();
}

template <int N>
class C {};
void test_constexpr() {
  auto add = [](int x) constexpr {
    // printf("add(x), x=%d\n", x); // 此处加上后参数不能传常数
    return 5 + x;
  };

  auto f = [&](const int x) {
    // C<x> c1;  // error: ‘x’ is not a constant expression
    C<add(6)> c2;
  };

  const int a = 5;      // semantics：only read variable & constant
  C<a> c1;              // constant
  *(int*)(&a) = 6;      // variable
  printf("a=%d\n", a);  // 5
  C<add(a)> c2;         // constexpr is constant, print of add function is not running

  const int* p = &a;
  printf("*p=%d\n", *p);  // 6
}

// tuple
void test_tuple() {
  // constructor
  auto t1 = std::make_tuple(Item{1, "n1", 100}, 1, std::string{"hongkong"});  // make_tuple
  std::tuple<Item, int, std::string> t2(t1);                                  // copy
  std::tuple<std::string, int> t3;                                            // default
  std::tuple<int, int> t4 = {10, 1};                                          // implicit conversion
  std::tuple<int, int> t5{10, 1};                                             // implicit conversion
  // std::cout << std::get<int>(t4) << "\n";    // error

  auto p1 = std::make_pair("p", 1);
  std::tuple<std::string, int> t6(p1);

  // std::invaild_argument
  auto func = [](int id) -> std::tuple<double, char, std::string> {
    if (id == 0) return std::make_tuple(1.1, 'A', "Lisa");
    if (id == 1) return std::make_tuple(1.2, 'C', "Jack");
    if (id == 2) return std::make_tuple(1.3, 'B', "Rose");
    throw std::invalid_argument("id");
  };

  try {
    func(4);  // error, throw
  } catch (std::invalid_argument& e) {
    std::cerr << "Error:" << e.what() << std::endl;
  }

  // read, three ways
  auto s1 = func(0);
  std::cout << "ID(0),"
            << "GPA:" << std::get<0>(s1)
            << ","
            // << "grade:" << std::get<1>(s1) << ","
            << "grade:" << std::get<char>(s1) << ","  // only type can apply
            << "name:" << std::get<2>(s1) << "\n";

  double gpa1;
  char grade1;
  std::string name1;
  std::tie(gpa1, grade1, name1) = func(1);  // assignment
  // std::tie(gpa1, std::ignore, name1 ) = func(1);
  std::cout << "ID(1),"
            << "GPA:" << gpa1 << ","
            << "grade:" << grade1 << ","
            << "name:" << name1 << "\n";

  auto [gpa2, grade2, name2] = func(2);
  std::cout << "ID(2),"
            << "GPA:" << gpa2 << ","
            << "grade:" << grade2 << ","
            << "name:" << name2 << "\n";

  // compare
  std::cout << std::boolalpha << (func(0) < func(1)) << "\n";
  std::cout << (std::tie(gpa1, grade1, name1) < func(2)) << "\n";
  std::cout << (std::tie(grade1, gpa1, name1) < std::tie(grade2, gpa2, name2))
            << "\n";  // make an order for compare
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

// dirname, basename
void test_dirname() {
  std::string s = "/data/shell/test/tmp/a.txt";  // /data/shell/test/tmp
  // std::string s = "/data/shell/test/tmp/";       // /data/shell/test/
  // std::string s = "/data/shell/test/tmp";        // /data/shell/test/
  auto path = dirname(const_cast<char*>(s.c_str()));
  printf("path=%s\n", path);
}

// 函数指针
int callback(int a) { return a + 5; }
void test_func_as_args(func_callback f) {
  printf("test_func_as_args=%d\n", f(10));
  // test_func_as_args(callback); //调用
}