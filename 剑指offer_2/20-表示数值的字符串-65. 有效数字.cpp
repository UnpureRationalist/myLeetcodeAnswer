#include "header.h"

class Solution {
  bool scanInteger(const char *&str) {
    if (*str == '+' || *str == '-') {
      ++str;  // 去除 + - 号
    }
    return scanUnsignedInteger(str);  // 剩余部分应为无符号数
  }

  bool scanUnsignedInteger(const char *&str) {
    const char *before = str;
    // 读取到字符串末尾或者第一个非数字字符
    while (*str != '\0' && *str >= '0' && *str <= '9') {
      ++str;
    }
    return str > before;
  }

  bool isNumber(const char *str) {
    if (str == nullptr) {
      return false;
    }
    bool legal = scanInteger(str);  // 获取整数部分
    if (*str == '.') {              // 如果有小数点
      ++str;

      legal = scanUnsignedInteger(str) || legal;  // 整数部分可能不存在，因此此处是 ||
    }

    if (*str == 'e' || *str == 'E') {
      ++str;

      legal = legal && scanInteger(str);  // 如果有指数，前面不能为空，因此这里为 &&
    }
    return legal && *str == '\0';  // 必须到达字符串尾部
  }

 public:
  bool isNumber(string s) { return isNumber(s.c_str()); }
};
