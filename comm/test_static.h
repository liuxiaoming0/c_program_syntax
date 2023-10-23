#ifndef CBE2D46E_CF09_45C1_A5AF_CB6A38976FD4
#define CBE2D46E_CF09_45C1_A5AF_CB6A38976FD4
#include "test.h"

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

#endif /* CBE2D46E_CF09_45C1_A5AF_CB6A38976FD4 */
