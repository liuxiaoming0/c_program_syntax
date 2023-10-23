#ifndef FA1DF9F2_3F45_47BE_8CD1_AACAA069B959
#define FA1DF9F2_3F45_47BE_8CD1_AACAA069B959
#include "test.h"

// dirname, basename
void test_dirname() {
  std::string s = "/data/shell/test/tmp/a.txt";  // /data/shell/test/tmp
  // std::string s = "/data/shell/test/tmp/";       // /data/shell/test/
  // std::string s = "/data/shell/test/tmp";        // /data/shell/test/
  auto path = dirname(const_cast<char*>(s.c_str()));
  printf("path=%s\n", path);
}

#endif /* FA1DF9F2_3F45_47BE_8CD1_AACAA069B959 */
