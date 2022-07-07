#include "appcomm.h"

int32_t E_a = 2;   // 头文件声明，此处定义
int32_t E_d = 19;  // 默认extern，声明和定义
static int32_t E_f = 20; // 不在头文件，不会有这种写法，因为不能被其他源文件使用了