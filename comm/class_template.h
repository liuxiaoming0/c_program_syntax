/*
  模板类
*/

#pragma once

#include "appcomm.h"

template <typename T>
class CData {
 public:
  CData() : sort_finish_(false) {}
  ~CData() { datas_.clear(); }

  void Insert(const T& data) { datas_.push_back(data); }
  void Insert(const T&& data) { datas_.push_back(data); }
  T& operator[](int i) { return datas_[i]; }
  typename std::vector<T>::iterator Begin() { return datas_.begin(); }
  typename std::vector<T>::iterator End() { return datas_.end(); }
  typename std::vector<T>::const_iterator Begin() const {
    return datas_.begin();
  }
  typename std::vector<T>::const_iterator End() const { return datas_.end(); }
  void Sort(std::function<bool(const T&, const T&)> cmp);
  void Print();

 private:
  CData(const CData&) = delete;
  CData& operator=(const CData&) = delete;
  std::vector<T> datas_;
  bool sort_finish_;
};

template <typename T>
void CData<T>::Sort(std::function<bool(const T& left, const T& right)> cmp) {
  std::sort(datas_.begin(), datas_.end(), cmp);
  sort_finish_ = true;
}

template <typename T>
void CData<T>::Print() {
  printf("CData print:\n");
  for (const auto& one : datas_) {
    printf("id=%d, name=%s, amt=%ld\n", one.id, one.name.c_str(), one.amt);
  }
}
