#ifndef DE1DB72F_C7F9_4320_9529_CEA55161AD06
#define DE1DB72F_C7F9_4320_9529_CEA55161AD06
#include "test.h"

class Base1 {};
class Base2 {virtual void print(){};};
class Driverd : public Base1 {};

void test_class_polymorphism() {
  Base1 b1;
  std::cout << "sizeof(Base1) = " << sizeof(Base1) << std::endl;
  std::cout << "sizeof(b1) = " << sizeof(b1) << std::endl;
  std::cout << "sizeof(Base2) = " << sizeof(Base2) << std::endl;
}

#endif /* DE1DB72F_C7F9_4320_9529_CEA55161AD06 */


