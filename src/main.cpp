#include "../comm/test.h"

//类外编译时初始化分配空间，其他地方容易重复定义
// std::string Ccfg::cfg_path_ = "";

int main(int argc, char** argv) { test_double_ptr(); }