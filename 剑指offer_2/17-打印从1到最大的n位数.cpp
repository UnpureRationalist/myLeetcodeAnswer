#include "header.h"

// 方法 1：模拟大整数

// 方法 2：全排列
class Solution {
 private:
  void printStr(const string &str) {
    const char *s = str.c_str();
    while (*s == '0') {
      ++s;
    }
    if (*s) {
      cout << s << endl;  // 避免全 0 占行
    }
  }

  void dfs(string &s, int length, int index) {
    if (index == length) {
      printStr(s);
      return;
    }
    for (int i = 0; i < 10; ++i) {
      s[index] = '0' + i;
      dfs(s, length, index + 1);
    }
  }

 public:
  void print1ToMaxOfNDigits(int n) {
    string s(n, '0');
    dfs(s, n, 0);
  }
};

int main() {
  Solution s;
  s.print1ToMaxOfNDigits(3);
  return 0;
}