#include "../comm/test.h"
#include "../comm/class_static.h"

//类外编译时初始化分配空间，其他地方容易重复定义
// std::string Ccfg::cfg_path_ = "";

int main(int argc, char** argv) {
  // auto cfg = make_shared<CIncomeCfg>(10);
  // int res = cfg->print_cnt(cfg);
  // cout << res << endl;
  test_constexpr();
  return 0;
}