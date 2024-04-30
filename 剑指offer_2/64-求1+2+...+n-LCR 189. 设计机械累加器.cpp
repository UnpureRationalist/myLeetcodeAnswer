#include "header.h"

class Solution {
 public:
  int mechanicalAccumulator(int n) {
    bool arr[n][n + 1];
    return sizeof(arr) >> 1;
  }
};

// 其它方法：
// 1. 利用构造函数 及 类静态变量
// 2. 利用虚函数
// 3. 利用函数指针（类似虚函数）
// 4. 利用模板类型（有递归深度限制，仅能求解 n 较小的情况 且 不能动态输入，编译期 n 必须确定）