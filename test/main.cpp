// Copyright 2020 Tencent Inc.  All rights reserved.
#include <iostream>
#include "google_test.h"

using namespace std;
int main(int argc, char* argv[]) {
  // testing::GTEST_FLAG(output) = "xml:"; //若要生成xml结果文件
  testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
}