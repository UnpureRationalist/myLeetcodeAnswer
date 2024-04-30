#include "header.h"

class Solution {
  int str2intCore(const char *digit, bool minus) {
    long long num = 0;
    while (*digit != '\0') {
      if (*digit >= '0' && *digit <= '9') {
        int flag = minus ? -1 : 1;
        num = num * 10 + flag * (*digit - '0');
        if (!minus && num > INT32_MAX) {  // 正溢出
          num = INT32_MAX;
          break;
        }
        if (minus && num < INT32_MIN) {  // 负溢出
          num = INT32_MIN;
          break;
        }
        ++digit;
      } else {
        break;
      }
    }
    return num;
  }

  int str2int(const char *str) {
    long long num = 0;
    if (str == nullptr || *str == '\0') {
      return num;
    }
    // 去掉前导空格
    while (*str == ' ') {
      ++str;
    }
    // 处理正负号
    bool minus = false;
    if (*str == '+') {
      ++str;
    } else if (*str == '-') {
      minus = true;
      ++str;
    }
    if (*str != '\0') {
      num = str2intCore(str, minus);
    }
    return num;
  }

 public:
  int myAtoi(string s) { return str2int(s.c_str()); }
};
