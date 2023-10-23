#include <iostream>

class TINITAL {
 public:
  TINITAL(int a, int b): a_(a), b_(b){};
  // explicit TINITAL(int a, int b): a_(a), b_(b){}; // initializer list can`t used
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
  // TINITAL t1 = {1,2};
  // TINITAL t1 (1,2);
  TINITAL t1 {1,2};
  std::cout << t1.GetA() << " " << t1.GetB() << std::endl;

  TINITALS t2 = {11,12,13};
  std::cout << t2.GetA() << " " << t2.GetB() << " " << t2.GetC() << std::endl;
}