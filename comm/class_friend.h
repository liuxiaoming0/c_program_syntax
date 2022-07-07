#pragma once
#include "appcomm.h"
#include "class_print.h"

// two classes must in a file
class CShow;
class CShow_one {  // must before, otherwise compile error
 public:
  void showInt(std::shared_ptr<CShow> p);  // only statement, can`t define
};

class CShow {
 public:
  CShow() = default;
  CShow(int a) { a_ = a; };
  static void getPrintItem(std::shared_ptr<Cprint> p) {
    printf("CShow(), id=%d, name=%s, amt=%ld\n", p->data_.id, p->data_.name.c_str(), p->data_.amt);
  };
  friend void CShow_one::showInt(std::shared_ptr<CShow> p);

 private:
  int a_;
};
