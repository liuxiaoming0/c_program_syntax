#ifndef DE1DB72F_C7F9_4320_9529_CEA55161AD06
#define DE1DB72F_C7F9_4320_9529_CEA55161AD06
#include "test.h"

class Base {};

void test_class_polymorphism() {
  Base b1;
  std::cout << "sizeof(Base) = " << sizeof(Base) << std::endl;
  std::cout << "sizeof(b1) = " << sizeof(b1) << std::endl;
}

#endif /* DE1DB72F_C7F9_4320_9529_CEA55161AD06 */




