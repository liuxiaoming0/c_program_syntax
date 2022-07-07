# 安装
参考：
安装参考：https://blog.csdn.net/jcjc918/article/details/52029455
https://www.cnblogs.com/helloworldcode/p/9606838.html
https://www.cnblogs.com/coderzh/archive/2009/04/06/1426755.html
## 方法1：git clone master 源码安装，报错
    安装cmake2.8版本以上
    参考：https://segmentfault.com/a/1190000021911081
    纠正：sudo ln -s cmake /usr/bin/cmake，需要用绝对路径，否则报错
## 方法2：使用1.7版本
官方已经把 gtest 和 gmock 一起维护，所以这个 git 仓库还包含了 gmock

建议安装 gtest 1.7 release 版本（该安装方法对 1.8 不适用）

    wget https://github.com/google/googletest/archive/release-1.7.0.tar.gz
    tar xf release-1.7.0.tar.gz
    cd googletest-release-1.7.0 
    googletest-release-1.7.0 cmake -DBUILD_SHARED_LIBS=ON 
    googletest-release-1.7.0 make 
    googletest-release-1.7.0 sudo cp -a include/gtest /usr/include 
    googletest-release-1.7.0 sudo cp -a libgtest_main.so libgtest.so /usr/lib/

    libgtest.so -> libgtest.so
    libgtest_main.so -> libgtest_main.so

## 编译运行
- [makefile]链接增加-lgtest
- [makefile]动态或静态库、头文件，因为都在/usr/include、/usr/lib没有特别指定
- [makefile]需要调用被测试源文件的.cpp函数，因而也要参与编译生成.o文件，但是源代码的main.cpp中的入口函数不能包含其中
- [用例编写]头文件#include"gtest/gtest.h"
- [用例编写]语法参考文档即可