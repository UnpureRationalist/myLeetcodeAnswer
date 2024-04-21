#include "header.h"

// 力扣：LCR 122. 路径加密
class Solution {
 public:
  string pathEncryption(string path) {
    for (auto &c : path) {
      if (c == '.') {
        c = ' ';
      }
    }
    return path;
  }
};

// 剑指 offer：给定字符串，要求将空格替换为 "%20"，要求在原字符串替换，保证输入字符串有足够空间
class Solution2 {
 public:
  void replaceSpace(char *str) {
    if (str == nullptr) {
      return;
    }
    char *s = str;
    int space_num = 0;
    int str_len = 0;
    while (*s) {
      if (*s == ' ') {
        ++space_num;
      }
      ++str_len;
    }
    int replace_len = str_len + space_num * 2;
    char *origin_end = str + str_len;
    char *new_end = str + replace_len;
    while (origin_end >= str) {
      if (*origin_end == ' ') {
        *new_end = '0';
        new_end--;
        *new_end = '2';
        new_end--;
        *new_end = '%';
        new_end--;
        origin_end--;
      } else {
        *new_end = *origin_end;
        origin_end--;
        new_end--;
      }
    }
  }
};
