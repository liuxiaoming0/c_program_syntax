#include "../comm/test.h"
#include "../comm/class_static.h"
#include "../comm/test_initializer_list.h"
#include "../comm/test_map_shared_ptr_change.h"
#include "../comm/test_using.h"

//类外编译时初始化分配空间，其他地方容易重复定义
// std::string Ccfg::cfg_path_ = "";

int main(int argc, char** argv) {
  // auto cfg = make_shared<CIncomeCfg>(10);
  // int res = cfg->print_cnt(cfg);
  // cout << res << endl;
  test_using();
  return 0;
}