# 进度
    20220623（4）：makefile编写
    20220624（5）：模板变量、回调函数、匿名函数、运算符重载、移动构造函数、移动拷贝、编译类型自动推导、auto、移动拷贝std::move
    20220625（6）：extern、全局静态变量、局部静态变量、类静态变量&函数
    20220627（1）：类型转换static_cast、typeid、gcc4.8->8.3、std::any
    20220628（2）：inline内联函数、volatile
    20220629（3）：law pointer、shared_ptr、unique_ptr、weaker_ptr、define
    20220701（5）：virtual析构函数、explicit、constexpr
    20220702（6）：tuple、std::invalid_argument、完美转发、=default、=delete、override、final
    20220704（1）：profile性能分析、C++单元测试
    20220706（3）：上传github、补充gtest文档和用例、friend类、friend函数
    20220711（1）: 双重指针
    后续根据新语法持续更新。。。。。。。
# 1.C++编程
    运算符重载operator=()（√）
    拷贝构造函数、移动拷贝构造函数&&、赋值构造函数（√）
    extern、static局部变量变量、static全局变量、类静态成员变量、类静态成员函数（√）
    static_cast、const_cast、reinterpret_cast、dynamic_cast（√）
    RTTI(Runtime Type Identification)：typeid、dynamic_cast（√）
    inline、volatile、explicit、virtual析构函数（√）
    profile性能分析、C++单元测试googletest、friend类、friend公共函数、friend成员函数（√）
    **[pause]**
        - 深拷贝、浅拷贝、extern "C"、类的继承等
        - 模板类：函数模板、默认模板参数、可变参数模板
        - __func__、 __asm__、__asm__ volatile
# 2.C11新特性
    回调函数std::function（√）
    匿名函数auto func = [&](args1, ...)->decltype(a+b){}（√）
    lambda匿名函数（√）
    左值、纯右值、将亡值、移动拷贝std::move（√）
    decltype(a)类型自动推导、返回值类型后置（√）
    using= 定义别名，typedef定义别名（√）
    noexcept、列表初始化、constexpr常量（√）
    NULL是0，空指针nullptr、智能指针：shared_ptr、unique_ptr、weak_ptr（√）
    std::invalid_argument、tuple、完美转发（√）
    **[pause]**
        - std::atomic(线程)
# 3.C17新特性-可参考trpc-cpp
    std::any、std::any_cast、std::make_any、lambda常量表达式constexpr（√）
    **[pause]**
        - 逻辑运算符特征std::negation、std::disjunction、std::conjunction
        - 统一容器访问：std::size、std::byte、std::data、std::empty、std::variant、std::optional
        - 新算法：
          std::for_each_n、std::exclusive_scan、std::inclusive_scan
          std::transform_exclusive_scan、std::transform_inclusive_scan
          std::parallel::reduce、std::parallel::transform_reduce
        - STL并行版本
        - 头文件预处理运算符__has_include
        - 结构化绑定，pair、tuple、array
        - 类模板参数推导、变长模板、fold表达式
        - 带初始化的选择语句：if (auto it = int2StringMap.find(2); it != int2StringMap.end())
# 4.设计模型
    **[opening]**
    单例模式
    事件模型
    工厂模型
    数据库连接池：https://blog.csdn.net/wwh578867817/article/details/47029653
    多进程、多线程
    生成静态库、动态库、shell生成框架代码

# 5.第三方库&开源库
    gdb或vscode调试看代码：https://xusenqi.site/2019/12/23/Remote-Debug-Go-Code-with-Visual-Studio-Code/#more
    trpc：
    fable：
    mysql：http://c.biancheng.net/mysql/
    redis：http://c.biancheng.net/redis/
    队列、压测性能、业务性能、组件性能
    boost
    folly :https://github.com/facebook/folly
    gflags:https://github.com/gflags/gflags

# 6.数据结构STL：<http://c.biancheng.net/stl/>
    vector
    deque
    list
    map
    hash

# 7.算法：<http://c.biancheng.net/algorithm/what-is-algorithm.html>
    排序
    TOP10

# 8.makefile、bazel、gcc、汇编语言
    gcc版本区别
    gcc优化参数
    汇编语言
    底层代码实现
    cmake
    bazal
