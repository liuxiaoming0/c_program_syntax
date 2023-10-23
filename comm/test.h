#pragma once

#include <libgen.h>
#include <stdio.h>
#include <unistd.h>
#include <any>
#include <memory>
#include <iostream>
#include "appcomm.h"
#include "class_friend.h"
#include "class_print.h"
#include "class_static.h"
#include "class_template.h"

using namespace std;

// 公共函数
void print_vec(VEC_INTEM vecItem) noexcept;
void print_vec(VEC_INTEM_PTR vecItemPtr) noexcept;
#define LINE(s) printf("=======%s========\n", s)
#define RELASE_PTR(ptr) \
  if (NULL != ptr) {    \
    delete ptr;         \
    ptr = nullptr;      \
  }

// 函数指针
int callback(int a);
typedef int (*func_callback)(int a);
void test_func_as_args(func_callback f);
