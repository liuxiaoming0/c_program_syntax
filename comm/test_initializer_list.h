#include <iostream>

class TINITAL {
 public:
  TINITAL(int a, int b): a_(a), b_(b){};
  int GetA() { return a_; }
  int GetB() { return b_; }

 private:
  int a_, b_;
};
class TINITALS {
 public:
  TINITALS(std::initializer_list<int> list) {
    auto it = list.begin();
    a_ = *it++;
    b_ = *it++;
    c_ = *it++;
  }
  int GetA() { return a_; }
  int GetB() { return b_; }
  int GetC() { return c_; }
 private:
  int a_, b_, c_;
};

void test_initializer_list() {
  TINITALS t1 = {11,12,13};
  std::cout << t1.GetA() << " " << t1.GetB() << " " << t1.GetC() << std::endl;
}