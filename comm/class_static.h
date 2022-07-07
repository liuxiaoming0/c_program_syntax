#pragma once
#include "appcomm.h"

class Cprint;
class Ccfg {
 public:
  Ccfg(const int32_t& cnt) { cnt_ = cnt; };
  ~Ccfg(){};
  static std::string print_path() { return cfg_path_; }
  void set_path(const std::string& path) { cfg_path_ = path; }
  int32_t print_cnt() { return cnt_; }

 private:
  static std::string cfg_path_;
  int32_t cnt_;
};

// std::string Ccfg::cfg_path_ = ""; // multiple definition

class CIncomeCfg : public Ccfg {
 public:
  CIncomeCfg(const int32_t cnt) : Ccfg(cnt){};
  ~CIncomeCfg(){};
};