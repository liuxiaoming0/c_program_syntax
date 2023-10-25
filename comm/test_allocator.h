#ifndef ADC0868A_6D0C_4D17_AEC7_58C21EE5B0DA
#define ADC0868A_6D0C_4D17_AEC7_58C21EE5B0DA
#include "test.h"
class CAllocator {
public:
  CAllocator():id_(0), name_("") {
    cout << "CAllocator()" << endl;
  }
  CAllocator(int&& id, const string&& name) : id_(std::move(id)), name_(std::move(name)){
    cout << "CAllocator(id, name)" << endl;
  }
private:
 int id_;
 std::string name_;
};

void test_allocate() {
  shared_ptr<CAllocator[]> p1(new CAllocator[3]);  // 一定会初始化对象

  std::allocator<CAllocator> alloc;  // 实例化
  CAllocator* p = alloc.allocate(5);  // 申请内存
  for (size_t i=0; i!=5; ++i) {
    alloc.construct(p+i, 18, "mike");  // 构造对象
  }
  for (size_t i=0; i!=5; ++i) {
      alloc.destroy(p + i);  // 析构对象
  }
  alloc.deallocate(p, 5);  // 回收内存
}

#endif /* ADC0868A_6D0C_4D17_AEC7_58C21EE5B0DA */
