#pragma once

#include <stdio.h>
#include <unistd.h>
#include <any>
#include <memory>
#include "appcomm.h"
#include "class_friend.h"
#include "class_print.h"
#include "class_static.h"
#include "class_template.h"

// 公共函数
void print_vec(VEC_INTEM vecItem) noexcept;
void print_vec(VEC_INTEM_PTR vecItemPtr) noexcept;
#define LINE(s) printf("=======%s========\n", s)
#define RELASE_PTR(ptr) \
  if (NULL != ptr) {    \
    delete ptr;         \
    ptr = nullptr;      \
  }

// map指针修改
void change_map_ptr(VEC_INTEM_PTR vecItemPtr) noexcept;

// map存储指针
int test_map_ptr();

// 运行态打印迭代器类型typeid、类型转换
void test_map_type() noexcept;

// 任意类型std::any
void test_std_any();

// 编译时类型自动推导
void test_decltype();

// std::move原有t中string被清空，疑问：是重新分配地址的
void test_std_move();

// 测试CData模板类
void test_CData_template();

// 测试Cprint类，移动构造函数, 父子类, final，default, delete, override, final, friend
void test_Cprint_class();
void test_csprint_class();
void test_class_A();
void test_class_friend();

// static用法
void test_static();

// volatile
void test_vola();

// 智能指针
void test_ptr1();
void test_ptr2();
void test_ptr3();
void test_ptr4();

// 只读和常量
void test_constexpr();

// tuple结构类型
void test_tuple();

// 完美转发，区分左右值
void test_perfect_forward();
