/*
  类的构造、析构函数
*/
#pragma once
#include <ctime>
#include <iostream>
#include "appcomm.h"
#include "class_friend.h"

class CShow;
class Cprint {
 public:
  friend class CShow;
  Cprint() { printf("Cprint() [construct]\n"); }
  explicit Cprint(const Item& t) { printf("Cprint(&t) [construct]\n"); }
  Cprint(const Item&& t) {
    printf("Cprint(&&t) [construct]\n");
    data_ = t;
  }
  Cprint(const Cprint& c) { printf("Cprint [copy contruct]\n"); }
  Cprint(const Cprint&& c) { printf("Cprint [move copy contruct]\n"); }
  Cprint& operator=(const Cprint& p) {
    printf("Cprint [assign construct]\n");
    // 拷贝变量
    return *this;
  }
  ~Cprint() { printf("Cprint [destruct]\n"); }  // 一定要有virtual
  void printT() { printf("test\n"); }
  friend void fri_func(const Cprint&);

 private:
  Item data_;
};

class CSprint : public Cprint {
 public:
  CSprint() { printf("CSprinf [contruct]\n"); }
  ~CSprint() { printf("CSprint [destruct]\n"); }
};

class A {
  // class A final{ // B error
 public:
  A() = default;
  A(int i) : i_(i){};
  A(const A& a) = delete;

  virtual void func(int a, std::string s){};
  // virtual void func(int a, std::string s) {}; // B func() override , error

 private:
  int i_;
};

class B : public A {
  void func(int a, std::string s) override{};
};

class Cprofile {
 public:
  Cprofile(const std::string& name) {
    name_ = name;
    start_ = time(0);
  };
  Cprofile(const Cprofile&) = delete;
  ~Cprofile() {
    time_t end_ = time(0);
    double diff = difftime(time(0), start_);
    printf("%s spend %d seconds\n", name_.c_str(), static_cast<int>(diff));
  }

 private:
  std::string name_;
  time_t start_;
};
